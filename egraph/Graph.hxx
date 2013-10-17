#ifndef GRAPH_HXX
#define GRAPH_HXX

#include <GraphFwd.hxx>

#include <EdgeDirections.hxx>
#include <EdgeRoles.hxx>

#include <Vertex.hxx>
#include <Edge.hxx>

namespace EGraph {
class Graph
{
public:
    static Id invalidId();
    static Id createId();
    static bool isValidId(const Id& id);

    static std::ostream& debug(const VertexSPV& v, const String& title, std::ostream& strm = std::cout);
    static std::ostream& debug(const EdgeSPV& v, const String& title, std::ostream& strm = std::cout);

    explicit Graph(const String& fname = "");
    virtual ~Graph();

    void setFileName(const String& n);

    String fileName() const;

    const VertexSPV verticesWithType(const String& t) const;
    const EdgeSPV edges(VertexSP start, EdgeDirections direction) const;

    VertexSP createVertex(const String &typeName = "", const String& lbl = "");
    VertexSP vertex(const Id& id) const;

    EdgeSP createEdge(VertexSP left, VertexSP right, EdgeRoles r = EdgeRoles::Unspecified, EdgeDirections d = EdgeDirections::Out);

    void debug(std::ostream& strm = std::cout) const;
    void debugVertices(std::ostream& strm = std::cout) const;
    void debugEdges(std::ostream& strm = std::cout) const;

private:
    friend class boost::serialization::access;

    template<class Archive>
        void serialize(Archive& a, const unsigned int v)
        {
            (void) v;
            a & BOOST_SERIALIZATION_NVP(m_fname);
            a & BOOST_SERIALIZATION_NVP(m_vertices);
            a & BOOST_SERIALIZATION_NVP(m_edges);
        }

    String m_fname;
    VertexSPM m_vertices;
    EdgeSPM m_edges;
};
}

BOOST_CLASS_EXPORT_KEY(EGraph::Graph)

BOOST_CLASS_VERSION(EGraph::Graph, 1)

#endif // GRAPH_HXX
