#include "Database.hxx"

#include <db/Schema.hxx>

QString Database::dataSchemaName()
{
    return "DTA";
}

Database::Database(const QString& n)
    : AbstractDbNode(), m_name(n)
{
    (void) create<Schema, Database>(this, Database::dataSchemaName());
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
