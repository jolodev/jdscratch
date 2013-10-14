#include "Table.hxx"

#include "TableColumn.hxx"

Table::Table(Schema *s, const QString &n)
    : InSchemaNode(s, n)
{
}

Table::~Table()
{

}

void Table::setIsAudited(bool b)
{
    m_isAudited = b;
}

bool Table::isAudited() const
{
    return m_isAudited;
}

TableColumnSP Table::firstColumnWithRole(PropertyRole r)
{
    for (auto c : nodes<TableColumn>()) {
        if (c->hasRole(r)) {
            return c;
        }
    }

    return TableColumnSP();
}
