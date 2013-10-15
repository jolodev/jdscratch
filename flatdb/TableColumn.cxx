#include "TableColumn.hxx"

#include <DataType.hxx>

#include <Tools.hxx>

QString TableColumn::staticSingular()
{
    return "COLUMN";
}

QString TableColumn::staticPlural()
{
    return "COLUMNS";
}

TableColumn::TableColumn(DatabaseP db, const Id &parentId, const Id &id, const QString &n, const QString &c)
    : InTableNode(db, parentId, id, n, c)
{
}

TableColumn::~TableColumn()
{

}

void TableColumn::setDataType(DataTypeSP t)
{
    m_dataType = t;
}

void TableColumn::setRole(ColumnRoles r)
{
    m_role = r;
}

DataTypeSP TableColumn::dataType() const
{
    return m_dataType;
}

ColumnRoles TableColumn::role() const
{
    return m_role;
}

QString TableColumn::implToString() const
{
    return QObject::tr("%1: %2 %3 [Role: %4]")
            .arg(singular())
            .arg(qualifiedName())
            .arg(optionalToString<DataType>(dataType()))
            .arg(roleToString(role()));
}

QString TableColumn::implSingular() const
{
    return TableColumn::staticSingular();
}

QString TableColumn::implPlural() const
{
    return TableColumn::staticPlural();
}
