#include "Vertex.hxx"

BOOST_CLASS_EXPORT_IMPLEMENT(EGraph::Vertex)

#include <Graph.hxx>

using namespace EGraph;

String Vertex::idPropertyName()
{
    return "_id";
}

String Vertex::labelPropertyName()
{
    return "_label";
}

String Vertex::typePropertyName()
{
    return "_vertex_type";
}

Vertex::Vertex(GraphP g, const String &lbl, const String &typeName)
    : m_g(g)
{
    (void) createProperty<Id>(Vertex::idPropertyName(), Graph::createId());
    (void) createProperty<String>(Vertex::labelPropertyName(), lbl);
    (void) createProperty<String>(Vertex::typePropertyName(), typeName);
}

Vertex::~Vertex()
{

}

void Vertex::registerProperty(AbstractVertexPropertySP p)
{
    m_properties[p->name()] = p;
}

GraphP Vertex::graph() const
{
    return m_g;
}

String Vertex::toString() const
{
    StringStream s;
    s << type() << ": " << label() << ": {" << id() << "}";
    return s.str();
}

Id Vertex::id() const
{
    return property<Id>(Vertex::idPropertyName())->value();
}

String Vertex::label() const
{
    return property<String>(Vertex::labelPropertyName())->value();
}

String Vertex::type() const
{
    return property<String>(Vertex::typePropertyName())->value();
}

StringVector Vertex::propertyNames() const
{
    auto v = StringVector();

    for (auto p : m_properties) {
        v.push_back(p.first);
    }

    return v;
}

AbstractVertexPropertySPV Vertex::properties() const
{
    auto v = AbstractVertexPropertySPV();

    for (auto p : m_properties) {
        v.push_back(p.second);
    }

    return v;
}

