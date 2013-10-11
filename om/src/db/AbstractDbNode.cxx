#include "AbstractDbNode.hxx"

AbstractDbNode::AbstractDbNode()
{
}

AbstractDbNode::~AbstractDbNode()
{

}

AbstractDbNode *AbstractDbNode::parent() const
{
    return implParent();
}

QString AbstractDbNode::name() const
{
    return implName();
}

QString AbstractDbNode::qualifiedName() const
{
    return implQualifiedName();
}

QString AbstractDbNode::makeIdentifier(const QString &n)
{
    return n.toUpper().replace(" ", "_");
}

void AbstractDbNode::registerNode(AbstractDbNodeSP n)
{
    m_nodesV.push_back(n);
    m_nodesM[n->name()] = n;
}
