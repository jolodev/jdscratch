#ifndef ABSTRACTVERTEXREQUEST_HXX
#define ABSTRACTVERTEXREQUEST_HXX

#include "AbstractRequest.hxx"

namespace EGraph {
class AbstractVertexRequest : public AbstractRequest
{
public:
    explicit AbstractVertexRequest();
    virtual ~AbstractVertexRequest();
};
}

#endif // ABSTRACTVERTEXREQUEST_HXX
