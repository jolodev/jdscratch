#include <PostgresDialect.hxx>

#include <Database.hxx>
#include <Schema.hxx>
#include <DataType.hxx>
#include <Extension.hxx>
#include <Table.hxx>
#include <TableColumn.hxx>

PostgresDialect::PostgresDialect()
    : AbstractSqlDialect()
{

}

PostgresDialect::~PostgresDialect()
{

}

void PostgresDialect::implCreate(const SchemaSP &s, QStringList &buf) const
{
    buf.append(QString("CREATE SCHEMA %1;").arg(s->name()));
}

void PostgresDialect::implCreate(const ExtensionSP &e, QStringList &buf) const
{
    buf.append(QString("CREATE EXTENSION %1 WITH SCHEMA %2;").arg(e->name()).arg(e->parentNode()->name()));
}

void PostgresDialect::implCreate(const TableSP &t, QStringList &buf) const
{
    QStringList tmp;

    tmp << QString("CREATE TABLE %1 (").arg(t->qualifiedName());
    tmp << ");";

    buf.append(tmp.join("\n"));
}
