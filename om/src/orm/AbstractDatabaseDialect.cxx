#include "AbstractDatabaseDialect.hxx"

AbstractDatabaseDialect::AbstractDatabaseDialect()
{
}

AbstractDatabaseDialect::~AbstractDatabaseDialect()
{

}

void AbstractDatabaseDialect::create(SchemaSP s, QStringList &buf) const
{
    implCreate(s, buf);
}

void AbstractDatabaseDialect::create(TableSP t, QStringList &buf) const
{
    implCreate(t, buf);
}

QString AbstractDatabaseDialect::command(const QString &c) const
{
    return c + ";";
}
