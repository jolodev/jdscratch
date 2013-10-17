#include "Graph.hxx"

Graph::Graph()
{
}

Graph::~Graph()
{

}

void Graph::printOn(std::ostream &strm) const
{
    strm << std::endl << "=== BEGIN ===";
    strm << std::endl << "--- Nodes ---";

    for (auto n : m_nodes) {
        strm << std::endl << n->toString();
    }

    strm << std::endl << "--- Edges ---";
    for (auto e : m_edges) {
        strm << std::endl << e->toString();
    }
    strm << std::endl << "=== END ===" << std::endl;
}

void Graph::printEdgesWithLeftNode(AbstractNodeSP n, std::ostream &strm) const
{
    strm << std::endl << "Edges with left node to " << n->toString();

    for (auto e : edgesWithLeft(n)) {
        strm << std::endl << "\t" << e->toString();
    }
}

void Graph::printEdgesWithRightNode(AbstractNodeSP n, std::ostream &strm) const
{
    strm << std::endl << "Edges with right node to " << n->toString();

    for (auto e : edgesWithRight(n)) {
        strm << std::endl << "\t" << e->toString();
    }
}

AbstractEdgeSP Graph::createEdge(EdgeTypes t, AbstractNodeSP l, AbstractNodeSP r)
{
    auto e = std::make_shared<Edge>(Edge(t, l, r));
    m_edges.push_back(e);
    return e;
}
