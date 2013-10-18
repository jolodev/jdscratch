#include "VertexRequest.hxx"

using namespace EGraph;

VertexRequest::VertexRequest()
    : AbstractVertexRequest()
{
}

VertexRequest::~VertexRequest()
{

}

String VertexRequest::implData() const
{
    StringStream s;
    return s.str();
}
