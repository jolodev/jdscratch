#include "AbstractNode.hxx"

AbstractNode::AbstractNode()
{
}

AbstractNode::~AbstractNode()
{

}

QString AbstractNode::toString() const
{
    return implToString();
}

QString AbstractNode::singular() const
{
    return implSingular();
}

AbstractNodeP AbstractNode::parent() const
{
    return implParent();
}

QString AbstractNode::name() const
{
    return implName();
}

QString AbstractNode::comment() const
{
    return implComment();
}

const AbstractNodeSPV &AbstractNode::childNodes() const
{
    return implChildNodes();
}
