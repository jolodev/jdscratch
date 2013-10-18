#ifndef VERTEXREQUEST_HXX
#define VERTEXREQUEST_HXX

#include "AbstractVertexRequest.hxx"

namespace EGraph {
class VertexRequest : public AbstractVertexRequest
{
public:
    explicit VertexRequest();
    virtual ~VertexRequest();

protected:
    virtual String implData() const;
};
}

#endif // VERTEXREQUEST_HXX
