#include "TableColumn.hxx"

TableColumn::TableColumn(Table *t, const QString &n, const QString &tn)
    : InTableNode(t, n), m_typeName(tn)
{
}

TableColumn::~TableColumn()
{

}

void TableColumn::setTypeName(const QString &n)
{
    m_typeName = n;
}

QString TableColumn::typeName() const
{
    return m_typeName;
}

void TableColumn::setRoles(const std::vector<PropertyRole> r)
{
    m_roles = r;
}

void TableColumn::setNotNull(bool nn)
{
    m_notNull = nn;
}

bool TableColumn::notNull() const
{
    return m_notNull;
}

void TableColumn::setDefaultExpression(const QString &expr)
{
    m_defaultExpression = expr;
}

bool TableColumn::hasRole(PropertyRole r) const
{
    for (auto i : m_roles) {
        if (r == i) {
            return true;
        }
    }

    return false;
}

QString TableColumn::defaultExpression() const
{
    return m_defaultExpression;
}
