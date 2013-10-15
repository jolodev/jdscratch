#include "Table.hxx"

QString Table::staticSingular()
{
    return "TABLE";
}

Table::Table(AbstractNodeP p, const QString &n, const QString &c)
    : InSchemaNode(p, n, c)
{
}

Table::~Table()
{

}

QString Table::implSingular() const
{
    return Table::staticSingular();
}
