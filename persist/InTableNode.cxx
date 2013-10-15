#include "InTableNode.hxx"

#include <Table.hxx>

InTableNode::InTableNode(AbstractNodeP p, const QString &n, const QString &c)
    : Node(p, n, c)
{
}

InTableNode::~InTableNode()
{

}

TableP InTableNode::table() const
{
    return static_cast<TableP>(parent());
}
