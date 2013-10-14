#include "PgDialect.hxx"

#include <db/Database.hxx>
#include <db/Schema.hxx>
#include <db/Table.hxx>
#include <db/TableColumn.hxx>

QString PgDialect::name()
{
    return "PostgreSQL";
}

PgDialect::PgDialect()
{
}

PgDialect::~PgDialect()
{

}

void PgDialect::implCreate(SchemaSP s, QStringList &buf) const
{
    buf.append(command("CREATE SCHEMA " + s->name()));
}

void PgDialect::implCreate(TableSP t, QStringList &buf) const
{
    QStringList defs;
    QStringList constr;
    QStringList pkColNames;

    for (auto c : t->nodes<TableColumn>()) {
        defs.append(QString("%1 %2 DEFAULT %3").arg(c->name()).arg(c->typeName()).arg(c->defaultExpression()));

        if (c->hasRole(PropertyRole::PrimaryKey)) {
            pkColNames.append(c->name());
        }

        if (c->notNull()) {
            constr.append(command(QString("ALTER TABLE %1 ALTER COLUMN %2 SET NOT NULL").arg(t->qualifiedName()).arg(c->name())));
        } else {
            constr.append(command(QString("ALTER TABLE %1 ALTER COLUMN %2 DROP NOT NULL").arg(t->qualifiedName()).arg(c->name())));
        }
    }

    if (!pkColNames.empty()) {
        constr.append(command(QString("ALTER TABLE %1 ADD CONSTRAINT PK_%2 PRIMARY KEY (%3)")
                              .arg(t->qualifiedName())
                              .arg(t->name())
                              .arg(pkColNames.join(", "))));
    }
    buf.append(command("CREATE TABLE " + t->qualifiedName() + "(\n\t" + defs.join("\n\t, ") + "\n)"));
    buf.append(constr.join("\n"));

    if (t->isAudited()) {
        createAuditTableFor(t, buf);
        createAuditTriggerFor(t, buf);
        createVersioningTriggerFor(t, buf);
    }
}

void PgDialect::implDrop(SchemaSP s, QStringList &buf) const
{
    buf.append(command("DROP SCHEMA IF EXISTS %1 CASCADE").arg(s->name()));
}

void PgDialect::createAuditTableFor(TableSP t, QStringList &buf) const
{

    QStringList coldefs;
    for (auto c : t->nodes<TableColumn>()) {
        coldefs.append(QString("%1 %2").arg(c->name()).arg(c->typeName()));
    }

    coldefs.append("OPCODE TEXT NOT NULL");

    buf.append(command(QString("CREATE TABLE %1.%2 (\n\t%3\n)").arg(Database::auditSchemaName()).arg(t->name()).arg(coldefs.join("\n\t, "))));
}

void PgDialect::createAuditTriggerFor(TableSP dataT, QStringList &buf) const
{
    auto auditTableName = QString("%1.%2").arg(Database::auditSchemaName()).arg(dataT->name());
    auto auditFunctionName = QString("%1.AUDIT_%2").arg(Database::auditSchemaName()).arg(dataT->name());
    auto auditTriggerName = QString("TR_AUDIT_%1").arg(dataT->name());

    QStringList func;

    QStringList cols;

    QStringList iVals;
    QStringList uVals;
    QStringList dVals;

    for (auto c : dataT->nodes<TableColumn>()) {
        cols.append(c->name());
        iVals.append(QString("NEW.%1").arg(c->name()));
        uVals.append(QString("NEW.%1").arg(c->name()));
        dVals.append(QString("OLD.%1").arg(c->name()));
    }

    cols.append("OPCODE");
    iVals.append("'I'");
    uVals.append("'U'");
    dVals.append("'D'");

    func.append(QString("CREATE FUNCTION %1 ()").arg(auditFunctionName));
    func.append("RETURNS TRIGGER AS $$");
    func.append("DECLARE");
    func.append("BEGIN");
    func.append("\tIF 'INSERT' = TG_OP THEN");
    func.append(QString("\t\tINSERT INTO %1 (%2) VALUES (%3);").arg(auditTableName).arg(cols.join(", ")).arg(iVals.join(", ")));
    func.append("\t\tRETURN NEW;");
    func.append("\tELSIF 'UPDATE' = TG_OP THEN");
    func.append(QString("\t\tINSERT INTO %1 (%2) VALUES (%3);").arg(auditTableName).arg(cols.join(", ")).arg(uVals.join(", ")));
    func.append("\t\tRETURN NEW;");
    func.append("\tELSIF 'DELETE' = TG_OP THEN");
    func.append(QString("\t\tINSERT INTO %1 (%2) VALUES (%3);").arg(auditTableName).arg(cols.join(", ")).arg(dVals.join(", ")));
    func.append("\t\tRETURN OLD;");
    func.append("\tELSE");
    func.append("\t\tRAISE EXCEPTION 'Unknown TG_OP: %', TG_OP;");
    func.append("\tEND IF;");
    func.append("END;");
    func.append("$$ LANGUAGE PLPGSQL");

    buf.append(command(func.join("\n")));

    buf.append(command(QString("CREATE TRIGGER %1 AFTER INSERT OR UPDATE OR DELETE ON %2 FOR EACH ROW EXECUTE PROCEDURE %3()")
                       .arg(auditTriggerName)
                       .arg(dataT->qualifiedName())
                       .arg(auditFunctionName)));
}

void PgDialect::createVersioningTriggerFor(TableSP dataT, QStringList &buf) const
{
    auto funcN = QString("%1.VERSION_%2").arg(Database::auditSchemaName()).arg(dataT->name());
    auto versionColN = dataT->firstColumnWithRole(PropertyRole::Version)->name();
    auto versTriggerName = QString("TR_VERSION_%1").arg(dataT->name());

    QStringList func;
    func.append(QString("CREATE FUNCTION %1 ()").arg(funcN));
    func.append("RETURNS TRIGGER AS $$");
    func.append("DECLARE");
    func.append("BEGIN");
    func.append("\tIF 'INSERT' = TG_OP THEN");
    func.append(QString("\t\tNEW.%1 := 1;").arg(versionColN));
    func.append("\t\tRETURN NEW;");
    func.append(QString("\t\tNEW.%1 := NEW.%2 + 1;").arg(versionColN).arg(versionColN));
    func.append("\t\tRETURN NEW;");
    func.append("\t\tRETURN OLD;");
    func.append("\tELSE");
    func.append("\t\tRAISE EXCEPTION 'Unknown TG_OP: %', TG_OP;");
    func.append("\tEND IF;");
    func.append("END;");
    func.append("$$ LANGUAGE PLPGSQL");

    buf.append(command(func.join("\n")));

    buf.append(command(QString("CREATE TRIGGER %1 BEFORE INSERT OR UPDATE OR DELETE ON %2 FOR EACH ROW EXECUTE PROCEDURE %3()")
                       .arg(versTriggerName)
                       .arg(dataT->qualifiedName())
                       .arg(funcN)));
}
