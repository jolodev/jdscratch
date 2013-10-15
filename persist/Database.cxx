#include "Database.hxx"

#include <DataType.hxx>
#include <Schema.hxx>
#include <Extension.hxx>

QString Database::staticSingular()
{
    return "DATABASE";
}

Database::Database(const QString &n, const QString &c)
    : Node(nullptr, n, c)
{
    (void) createNode<DataType>(Config::BoolTypeName);
    (void) createNode<DataType>(Config::IntTypeName);
    (void) createNode<DataType>(Config::BigintTypeName);
    (void) createNode<DataType>(Config::NumericTypeName);
    (void) createNode<DataType>(Config::TextTypeName);
    (void) createNode<DataType>(Config::DateTypeName);
    (void) createNode<DataType>(Config::TimeTypeName);
    (void) createNode<DataType>(Config::TimestampTypeName);
    (void) createNode<DataType>(Config::UuidTypeName);

    (void) createNode<Schema>(Config::DataSchemaName);
    auto api = createNode<Schema>(Config::ApiSchemaName);
    (void) createNode<Schema>(Config::AuditSchemaName);

    api->createNode<Extension>(Config::UuidExtensionName);
}

Database::~Database()
{

}

QString Database::implSingular() const
{
    return Database::staticSingular();
}
