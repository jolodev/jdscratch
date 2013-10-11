#include "PgDialect.hxx"

#include <db/Schema.hxx>
#include <db/Table.hxx>

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
    buf.append(command("CREATE TABLE " + t->qualifiedName() + "()"));
}
