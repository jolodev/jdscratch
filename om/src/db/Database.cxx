#include "Database.hxx"

#include <db/Schema.hxx>

QString Database::dataSchemaName()
{
    return "DTA";
}

QString Database::auditSchemaName()
{
    return "AUDIT";
}

Database::Database(const QString& n)
    : AbstractDbNode(), m_name(n)
{
    (void) create<Schema, Database>(this, Database::dataSchemaName());
    (void) create<Schema, Database>(this, Database::auditSchemaName());
}

Database::~Database()
{

}

AbstractDbNode *Database::implParent() const
{
    return nullptr;
}

QString Database::implName() const
{
    return m_name;
}

QString Database::implQualifiedName() const
{
    return name();
}
