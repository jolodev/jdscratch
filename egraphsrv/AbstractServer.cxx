#include "AbstractServer.hxx"

#include <AbstractFormatDialect.hxx>

using namespace EGraph;

AbstractServer::AbstractServer()
{
}

AbstractServer::~AbstractServer()
{

}

void AbstractServer::setGraph(GraphSP g)
{
    implSetGraph(g);
}

GraphSP AbstractServer::graph() const
{
    return implGraph();
}

String AbstractServer::present(VertexSP v)
{
    return implPresent(v);
}

String AbstractServer::implPresent(VertexSP v)
{
    return dialect()->present(v);
}
