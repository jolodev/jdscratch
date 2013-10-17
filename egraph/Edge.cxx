#include "Edge.hxx"

BOOST_CLASS_EXPORT_IMPLEMENT(EGraph::Edge)

#include <Graph.hxx>
#include <Vertex.hxx>

using namespace EGraph;

String Edge::idPropertyName()
{
    return "_id";
}

String Edge::leftVertrexIdPropertyName()
{
    return "_left_vertex_id";
}

String Edge::rightVertexIdPropertyName()
{
    return "_right_vertex_id";
}

String Edge::directionPropertyName()
{
    return "_direction";
}

String Edge::rolePropertyName()
{
    return "_role";
}

Edge::Edge(GraphP g, VertexSP left, VertexSP right, const EdgeDirections d, const String r)
    : m_g(g)
{
    assert(m_g);
    (void) createProperty<Id>(Edge::idPropertyName(), Graph::createId());
    (void) createProperty<Id>(Edge::leftVertrexIdPropertyName(), left->property<Id>(Vertex::idPropertyName())->value());
    (void) createProperty<Id>(Edge::rightVertexIdPropertyName(), right->property<Id>(Vertex::idPropertyName())->value());
    (void) createProperty<EdgeDirections>(Edge::directionPropertyName(), d);
    (void) createProperty<String>(Edge::rolePropertyName(), r);
}

Edge::~Edge()
{

}

AbstractEdgePropertySPV Edge::properties() const {
    auto r = AbstractEdgePropertySPV();
    for (auto i : m_properties) {
        r.push_back(i.second);
    }
    return r;
}

Edge::Edge()
{
}

Id Edge::implLeftVertexId() const
{
    return property<Id>(Edge::leftVertrexIdPropertyName())->value();
}

Id Edge::implRightVertexId() const
{
    return property<Id>(Edge::rightVertexIdPropertyName())->value();
}

EdgeDirections Edge::implDirection() const
{
    return property<EdgeDirections>(Edge::directionPropertyName())->value();
}

String Edge::implRole() const
{
    return property<String>(Edge::rolePropertyName())->value();
}

void Edge::implSetDirection(EdgeDirections d)
{
    return property<EdgeDirections>(Edge::directionPropertyName())->setValue(d);
}

void Edge::implSetLeftVertexId(const Id &id)
{
    property<Id>(Edge::leftVertrexIdPropertyName())->setValue(id);
}

void Edge::implSetRightVertexId(const Id &id)
{
    property<Id>(Edge::rightVertexIdPropertyName())->setValue(id);
}

void Edge::implSetLeftVertex(VertexSP l)
{
    assert(l);
    setLeftId(l->property<Id>(Edge::leftVertrexIdPropertyName())->value());
}

void Edge::implSetRightVertex(VertexSP r)
{
    assert(r);
    setLeftId(r->property<Id>(Edge::rightVertexIdPropertyName())->value());
}

GraphP Edge::implGraph() const
{
    return m_g;
}

VertexSP Edge::implLeftVertex() const
{
    return graph()->vertex(leftVertexId());
}

VertexSP Edge::implRightVertex() const
{
    return graph()->vertex(rightVertexId());
}

Id Edge::implId() const
{
    return property<Id>(Edge::idPropertyName())->value();
}
