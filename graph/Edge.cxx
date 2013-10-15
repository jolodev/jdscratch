#include "Edge.hxx"

Edge::Edge(EdgeTypes t, AbstractNodeSP l, AbstractNodeSP r)
    : AbstractEdge(), m_type(t), m_id(createEdgeId()), m_left(l), m_right(r)
{
}

Edge::~Edge()
{

}

EdgeTypes Edge::implEdgeType() const
{
    return m_type;
}

Id Edge::implId() const
{
    return m_id;
}

AbstractNodeSP Edge::implLeft() const
{
    return m_left;
}

AbstractNodeSP Edge::implRight() const
{
    return m_right;
}

void Edge::implSetLeft(AbstractNodeSP l)
{
    m_left = l;
}

void Edge::implSetRight(AbstractNodeSP r)
{
    m_right = r;
}
