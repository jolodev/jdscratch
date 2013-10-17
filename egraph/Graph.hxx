#ifndef GRAPH_HXX
#define GRAPH_HXX

#include <GraphFwd.hxx>

#include <EdgeDirections.hxx>
#include <EdgeRoles.hxx>

#include <VertexFwd.hxx>
#include <EdgeFwd.hxx>

class Graph
{
public:
    static Id invalidId();
    static Id createId();
    static bool isValidId(const Id& id);

    explicit Graph();
    virtual ~Graph();

    void debug(std::ostream& strm) const;
    void debugVertices(std::ostream& strm) const;
    void debugEdges(std::ostream& strm) const;

    VertexSP createVertex(const String &typeName = "", const String& lbl = "");
    VertexSP vertex(const Id& id) const;

    EdgeSP createEdge(EdgeDirections d, VertexSP left, VertexSP right, EdgeRoles r = EdgeRoles::Unspecified);

private:
    VertexSPM m_vertices;
    EdgeSPM m_edges;
};

#endif // GRAPH_HXX
