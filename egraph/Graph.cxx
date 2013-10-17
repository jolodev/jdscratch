#include "Graph.hxx"

#include <Vertex.hxx>
#include <Edge.hxx>

#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/random_generator.hpp>

Id Graph::invalidId()
{
    return boost::uuids::nil_generator()();
}

Id Graph::createId()
{
    return boost::uuids::random_generator()();
}

bool Graph::isValidId(const Id &id)
{
    return (Graph::invalidId() != id);
}

Graph::Graph()
{
}

Graph::~Graph()
{

}

void Graph::debug(std::ostream &strm) const
{
    strm << std::endl << "== Begin of Graph ==" << std::endl;
    debugVertices(strm);
    debugEdges(strm);
    strm << std::endl << "== End of Graph ==" << std::endl;
}

void Graph::debugVertices(std::ostream &strm) const
{
    strm << std::endl << "-- Begin of Vertices ==" << std::endl;
    for (auto v : m_vertices) {
        strm << std::endl << "Vertex #" << v.second->property<Id>(Vertex::idPropertyName())->value();

        for (auto p : v.second->properties()) {
            strm << std::endl << "\t" << p->toString();
        }
    }
    strm << std::endl << "-- End of Vertices ==" << std::endl;
}

void Graph::debugEdges(std::ostream &strm) const
{
    strm << std::endl << "-- Begin of Edges ==" << std::endl;
    for (auto e : m_edges) {
        strm << std::endl << e.second->toString();
        for (auto p : e.second->properties()) {
            strm << std::endl << "\t" << p->toString();
        }
    }
    strm << std::endl << "-- End of Edges ==" << std::endl;
}

VertexSP Graph::createVertex(const String &typeName, const String &lbl)
{
    auto v = std::make_shared<Vertex>(this, lbl, typeName);
    m_vertices[v->property<Id>(Vertex::idPropertyName())->value()] = v;
    return v;
}

VertexSP Graph::vertex(const Id &id) const
{
    auto i = m_vertices.find(id);

    assert(m_vertices.end() != i);

    return (*i).second;
}

EdgeSP Graph::createEdge(EdgeDirections d, VertexSP left, VertexSP right, EdgeRoles r)
{
    auto e = std::make_shared<Edge>(Edge(this, d, left, right, r));
    m_edges[e->id()] = e;
    return e;
}
