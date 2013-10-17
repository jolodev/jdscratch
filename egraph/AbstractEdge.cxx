#include "AbstractEdge.hxx"

#include <EdgeDirections.hxx>
#include <Vertex.hxx>
#include <Graph.hxx>

AbstractEdge::AbstractEdge()
{
}

AbstractEdge::~AbstractEdge()
{

}

GraphP AbstractEdge::graph() const
{
    return implGraph();
}

EdgeDirections AbstractEdge::direction() const
{
    return implDirection();
}

EdgeRoles AbstractEdge::role() const
{
    return implRole();
}

Id AbstractEdge::id() const
{
    return implId();
}

Id AbstractEdge::leftId() const
{
    return implLeftId();
}

Id AbstractEdge::rightId() const
{
    return implRightId();
}

void AbstractEdge::setDirection(EdgeDirections d)
{
    implSetDirection(d);
}

void AbstractEdge::setLeftId(const Id &id)
{
    implSetLeftId(id);
}

void AbstractEdge::setRightId(const Id &id)
{
    implSetRightId(id);
}

void AbstractEdge::setLeftVertex(VertexSP v)
{
    implSetLeftVertex(v);
}

void AbstractEdge::setRightVertex(VertexSP v)
{
    implSetRightVertex(v);
}

void AbstractEdge::setVertices(VertexSP l, VertexSP r)
{
    setLeftVertex(l);
    setRightVertex(r);
}

String AbstractEdge::toString() const
{
    return implToString();
}

String AbstractEdge::implToString() const
{
    auto leftVertex = graph()->vertex(leftId());
    auto rightVertex = graph()->vertex(rightId());

    assert(leftVertex);
    assert(rightVertex);

    StringStream s;
    s << leftVertex->property<String>(Vertex::labelPropertyName())->value() << " [" << leftId() << "] ";
    s << edgeDirectionToString(direction()) << " ";
    s << rightVertex->property<String>(Vertex::labelPropertyName())->value() << " [" << rightId() << "]: ";
    s << edgeRoleToString(role());

    return s.str();
}
