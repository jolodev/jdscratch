#ifndef ABSTRACTREQUEST_HXX
#define ABSTRACTREQUEST_HXX

#include <Global.hxx>

#include <RequestTypes.hxx>

namespace EGraph {
class AbstractRequest
{
public:
    explicit AbstractRequest();
    virtual ~AbstractRequest();

    String data() const;
    RequestTypes requestType() const;

protected:
    virtual String implData() const = 0;
    virtual RequestTypes implRequestType() const = 0;
};
}

#endif // ABSTRACTREQUEST_HXX
