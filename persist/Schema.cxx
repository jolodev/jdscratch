#include "Schema.hxx"

#include <Database.hxx>
#include <Table.hxx>
#include <TableColumn.hxx>
#include <DataType.hxx>

#include <Tools.hxx>

QString Schema::staticSingular()
{
    return "SCHEMA";
}

Schema::Schema(AbstractNodeP p, const QString &n, const QString &c)
    : InDatabaseNode(p, n, c)
{
}

Schema::~Schema()
{

}

TableSP Schema::createValueTable(const QString &n, const QString &c)
{
    auto t = createNode<Table>(n, c);

    auto id = t->createNode<TableColumn>(Config::IdColName, "");
    assert(parent());
    std::cout << std::endl << "parent is: " << parent()->toString();
    assert(dynamic_cast<DatabaseP>(parent()));

    id->setDataType(database()->node<DataType>(Config::IdTypeName));
    return t;
}

QString Schema::implSingular() const
{
    return Schema::staticSingular();
}
