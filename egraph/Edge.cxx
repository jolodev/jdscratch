#include "Edge.hxx"

#include <Graph.hxx>
#include <Vertex.hxx>

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

Edge::Edge(GraphP g, const EdgeDirections d, VertexSP left, VertexSP right, const EdgeRoles r)
    : m_g(g)
{
    assert(g);
    (void) createProperty<Id>(Edge::idPropertyName(), Graph::createId());
    (void) createProperty<Id>(Edge::leftVertrexIdPropertyName(), left->property<Id>(Vertex::idPropertyName())->value());
    (void) createProperty<Id>(Edge::rightVertexIdPropertyName(), right->property<Id>(Vertex::idPropertyName())->value());
    (void) createProperty<EdgeDirections>(Edge::directionPropertyName(), d);
    (void) createProperty<EdgeRoles>(Edge::rolePropertyName(), r);
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

Id Edge::implLeftId() const
{
    return property<Id>(Edge::leftVertrexIdPropertyName())->value();
}

Id Edge::implRightId() const
{
    return property<Id>(Edge::rightVertexIdPropertyName())->value();
}

EdgeDirections Edge::implDirection() const
{
    return property<EdgeDirections>(Edge::directionPropertyName())->value();
}

EdgeRoles Edge::implRole() const
{
    return property<EdgeRoles>(Edge::rolePropertyName())->value();
}

void Edge::implSetDirection(EdgeDirections d)
{
    return property<EdgeDirections>(Edge::directionPropertyName())->setValue(d);
}

void Edge::implSetLeftId(const Id &id)
{
    property<Id>(Edge::leftVertrexIdPropertyName())->setValue(id);
}

void Edge::implSetRightId(const Id &id)
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

Id Edge::implId() const
{
    return property<Id>(Edge::idPropertyName())->value();
}
