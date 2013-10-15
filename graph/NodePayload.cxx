#include "NodePayload.hxx"

NodePayload::NodePayload(AbstractNode *n)
    : AbstractNodePayload(), m_n(n)
{
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

String NodePayload::implName() const
{
    return m_name;
}

String NodePayload::implComment() const
{
    return m_comment;
}
