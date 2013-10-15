#include "Database.hxx"

#include <Config.hxx>

#include <AbstractNode.hxx>
#include <DataType.hxx>
#include <Schema.hxx>
#include <Extension.hxx>
#include <Table.hxx>
#include <TableColumn.hxx>

Database::Database()
{
    bootstrap();
}

Database::~Database()
{

}

void Database::debug()
{
    std::cout << std::endl << " === BEGIN OF DUMP ===" << std::endl;

    for (auto n : m_nodeV) {
        std::cout << std::endl << n->toString();
    }

    std::cout << std::endl << " === END OF DUMP ===" << std::endl;
}

TableSP Database::createValueTable(const QString &n, const QString &c)
{
    auto t = createNode<Table>(n, nodeByName<Schema>(Config::ApiSchemaName)->id(), c);
/*
    auto id = t->createColumn(Config::Columns::IDColName, Config::Columns::IdTypeName, ColumnRoles::PrimaryKey);
    auto version = t->createColumn(Config::Columns::VersionColName, Config::Columns::VersionTypeName, ColumnRoles::Version);
    auto creator = t->createColumn(Config::Columns::CreatorColName, Config::Columns::CreatorTypeName, ColumnRoles::Creator);
    auto creation = t->createColumn(Config::Columns::CreationColName, Config::Columns::CreationTypeName, ColumnRoles::Creation);
    auto modificator = t->createColumn(Config::Columns::ModificatorColName, Config::Columns::ModificationTypeName, ColumnRoles::Modificator);
    auto modification = t->createColumn(Config::Columns::ModificationColName, Config::Columns::ModificationTypeName, ColumnRoles::Modification);
*/
    return t;
}

void Database::bootstrap()
{
    (void) createNode<DataType>(Config::BoolTypeName);
    (void) createNode<DataType>(Config::IntTypeName);
    (void) createNode<DataType>(Config::BigintTypeName);
    (void) createNode<DataType>(Config::NumericTypeName);
    (void) createNode<DataType>(Config::UuidTypeName);
    (void) createNode<DataType>(Config::TextTypeName);
    (void) createNode<DataType>(Config::TimestampTypeName);
    (void) createNode<DataType>(Config::TimeTypeName);
    (void) createNode<DataType>(Config::DateTypeName);

    (void) createNode<Schema>(Config::DataSchemaName);
    auto api = createNode<Schema>(Config::ApiSchemaName);
    (void) createNode<Schema>(Config::AuditSchemaName);

    (void) createNode<Extension>(Config::UuidExtensionName, api->id());
}

void Database::registerNode(AbstractNodeSP n)
{
    m_nodeV.push_back(n);
    m_nodeM[n->id()] = n;
}
