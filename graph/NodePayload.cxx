#include "NodePayload.hxx"

#include <AbstractNode.hxx>

NodePayload::NodePayload(AbstractNode *n)
    : AbstractNodePayload(), m_n(n), m_id { createNodeId() }
{
    assert(n);
    assert(m_n);
    assert(node());
}

NodePayload::~NodePayload()
{

}

AbstractNode *NodePayload::implNode() const
{
    return m_n;
}

void NodePayload::implSetName(const String &n)
{
    m_name = n;
}

void NodePayload::implSetComment(const String &c)
{
    m_comment = c;
}

Id NodePayload::implId() const
{
    return m_id;
}

String NodePayload::implName() const
{
    return m_name;
}

String NodePayload::implComment() const
{
    return m_comment;
}

String NodePayload::implToString() const
{
    StringStream s;
    s << "[in: ";

    if (node()) {
        s << node()->toString();
    } else {
        s << "<>";
    }

    s << "] " << name();
    return s.str();
}
