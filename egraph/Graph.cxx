#include "Graph.hxx"

BOOST_CLASS_EXPORT_IMPLEMENT(EGraph::Graph)

#include <Vertex.hxx>
#include <Edge.hxx>

#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/random_generator.hpp>

using namespace EGraph;

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

Graph::Graph(const String &fname)
    : m_fname(fname)
{
}

Graph::~Graph()
{

}

void Graph::setFileName(const String &n)
{
    m_fname = n;
}

String Graph::fileName() const
{
    return m_fname;
}

std::ostream &Graph::debug(const VertexSPV &v, const String &title, std::ostream &strm)
{
    strm << std::endl << "-- Vertices: " << title << " --";
    for (auto i : v) {
        strm << std::endl << "\t" << i->toString();
    }
    strm << std::endl;

    return strm;
}

std::ostream &Graph::debug(const EdgeSPV &v, const String &title, std::ostream &strm)
{
    strm << std::endl << "-- Edges: " << title << " --";
    for (auto i : v) {
        strm << std::endl << "\t" << i->toString();
    }
    strm << std::endl;

    return strm;
}

const VertexSPV Graph::verticesWithType(const String &t) const
{
    auto r = VertexSPV();

    for (auto i : m_vertices) {
        if (i.second->type() == t) {
            r.push_back(i.second);
        }
    }
    return r;
}

const EdgeSPV Graph::edges(VertexSP start, EdgeDirections d) const
{
    auto r = EdgeSPV();

    for (auto e : m_edges) {
        if (e.second->direction() == d) {
            if ((e.second->leftVertexId() == start->id())  || (e.second->rightVertexId() == start->id())) {
                r.push_back(e.second);
            }
        }
    }

    return r;
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
        strm << std::endl << v.second->toString();

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
    auto v = boost::make_shared<Vertex>(this, lbl, typeName);
    m_vertices[v->property<Id>(Vertex::idPropertyName())->value()] = v;
    return v;
}

VertexSP Graph::vertex(const Id &id) const
{
    auto i = m_vertices.find(id);

    assert(m_vertices.end() != i);

    return (*i).second;
}

EdgeSP Graph::createEdge(VertexSP left, VertexSP right, EdgeRoles r, EdgeDirections d)
{
    auto e = boost::make_shared<Edge>(Edge(this, left, right, d, r));
    m_edges[e->id()] = e;
    return e;
}
