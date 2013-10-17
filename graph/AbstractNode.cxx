#include "AbstractNode.hxx"

AbstractNode::AbstractNode()
{
}

AbstractNode::~AbstractNode()
{
}

String AbstractNode::toString() const
{
    return implToString();
}

Graph *AbstractNode::graph() const
{
    return implGraph();
}

Id AbstractNode::id() const
{
    return implId();
}

String AbstractNode::label() const
{
    return implLabel();
}
