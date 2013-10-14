#include "InTableNode.hxx"

#include <db/Schema.hxx>
#include <db/Table.hxx>

InTableNode::InTableNode(Table *t, const QString &n)
    : AbstractDbNode(), m_t(t), m_name(n)
{
}

InTableNode::~InTableNode()
{

}

Table *InTableNode::table() const
{
    return m_t;
}

QString InTableNode::implName() const
{
    return m_name;
}

QString InTableNode::implQualifiedName() const
{
    return table()->qualifiedName() + "." + name();
}

AbstractDbNodeRP InTableNode::implParent() const
{
    return m_t;
}
