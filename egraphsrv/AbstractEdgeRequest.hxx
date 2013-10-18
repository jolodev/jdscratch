#ifndef ABSTRACTEDGEREQUEST_HXX
#define ABSTRACTEDGEREQUEST_HXX

#include <AbstractRequest.hxx>

namespace EGraph {
class AbstractEdgeRequest : public AbstractRequest
{
public:
    explicit AbstractEdgeRequest();
    virtual ~AbstractEdgeRequest();
};
}

#endif // ABSTRACTEDGEREQUEST_HXX
