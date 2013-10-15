#include "AbstractNode.hxx"

AbstractNode::AbstractNode()
{
}

AbstractNode::~AbstractNode()
{

}

QString AbstractNode::singular() const
{
    return implSingular();
}

QString AbstractNode::plural() const
{
    return implPlural();
}

Id AbstractNode::parentId() const
{
    return implParentId();
}

Id AbstractNode::id() const
{
    return implId();
}

QString AbstractNode::name() const
{
    return implName();
}

QString AbstractNode::qualifiedName() const
{
    return implQualifiedName();
}

QString AbstractNode::comment() const
{
    return implComment();
}

QString AbstractNode::toString() const
{
    return implToString();
}

DatabaseP AbstractNode::database() const
{
    return implDatabase();
}
