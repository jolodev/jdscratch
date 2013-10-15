#include "Node.hxx"

Node::Node(AbstractNodeP p, const QString &n, const QString &c)
    : AbstractNode(), m_parent(p), m_name(n), m_comment(c)
{
}

Node::~Node()
{
}

void Node::registerChild(AbstractNodeSP c)
{
    assert(c);
    m_children.push_back(c);
}

const AbstractNodeSPV &Node::implChildNodes() const
{
    return m_children;
}

AbstractNodeP Node::implParent() const
{
    return m_parent;
}

QString Node::implName() const
{
    return m_name;
}

QString Node::implComment() const
{
    return m_comment;
}

QString Node::implToString() const
{
    return QString("%1: %2").arg(singular()).arg(name());
}
