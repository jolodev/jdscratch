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

Id AbstractEdge::leftVertexId() const
{
    return implLeftVertexId();
}

Id AbstractEdge::rightVertexId() const
{
    return implRightVertexId();
}

VertexSP AbstractEdge::leftVertex() const
{
    return implLeftVertex();
}

VertexSP AbstractEdge::rightVertex() const
{
    return implRightVertex();
}

void AbstractEdge::setDirection(EdgeDirections d)
{
    implSetDirection(d);
}

void AbstractEdge::setLeftId(const Id &id)
{
    implSetLeftVertexId(id);
}

void AbstractEdge::setRightId(const Id &id)
{
    implSetRightVertexId(id);
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

String AbstractEdge::connectionInfoToString(const EdgeDirections d, const EdgeRoles r) const
{
    StringStream s;

    switch(d) {
    case(EdgeDirections::In): {
        s << "<-- " /*<< edgeDirectionToString(d) << "/"*/ << edgeRoleToString(r) << " --";
        break;
    }
    case(EdgeDirections::Out): {
        s << "-- " /*<< edgeDirectionToString(d) << "/"*/ << edgeRoleToString(r) << " -->";
        break;
    }
    default: {
        s << "?-- " /*<< edgeDirectionToString(d) << "/"*/ << edgeRoleToString(r) << " --?";
        break;
    }
    }

    return s.str();
}

String AbstractEdge::implToString() const
{
    auto leftVertex = graph()->vertex(leftVertexId());
    auto rightVertex = graph()->vertex(rightVertexId());

    assert(leftVertex);
    assert(rightVertex);

    StringStream s;
    s << leftVertex->label();// << " [" << leftVertexId() << "] ";
    s << " " << connectionInfoToString(direction(), role()) << " ";
    s << rightVertex->label();// << " [" << rightVertexId() << "]";

    return s.str();
}
