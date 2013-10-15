#include "Table.hxx"

#include <Database.hxx>
#include <Schema.hxx>
#include <DataType.hxx>
#include <TableColumn.hxx>

QString Table::staticSingular()
{
    return "TABLE";
}

QString Table::staticPlural()
{
    return "TABLES";
}

Table::Table(DatabaseP db, const Id &parentId, const Id &id, const QString &n, const QString &c)
    : InSchemaNode(db, parentId, id, n, c)
{
}

Table::~Table()
{

}

TableColumnSP Table::createColumn(const QString &n, const QString &typeN, ColumnRoles r, const QString &c)
{
    auto col = database()->createNode<TableColumn>(n, id(), c);
    col->setDataType(database()->nodeByName<DataType>(typeN));
    col->setRole(r);
    return col;
}

QString Table::implSingular() const
{
    return Table::staticSingular();
}

QString Table::implPlural() const
{
    return Table::staticPlural();
}
