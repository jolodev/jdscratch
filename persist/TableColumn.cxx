#include "TableColumn.hxx"

#include <DataType.hxx>

QString TableColumn::staticSingular()
{
    return "COLUMN";
}

TableColumn::TableColumn(AbstractNodeP p, const QString& n, const QString& c)
    : InTableNode(p, n, c)
{
}

TableColumn::~TableColumn()
{

}

void TableColumn::setDataType(DataTypeSP t)
{
    m_type = t;
}

DataTypeSP TableColumn::dataType() const
{
    return m_type;
}

QString TableColumn::implSingular() const
{
    return TableColumn::staticSingular();
}
