#ifndef VALUENODEPAYLOAD_HXX
#define VALUENODEPAYLOAD_HXX

#include <NodePayload.hxx>

class ValueNodePayload : public NodePayload
{
public:
    static String singular();

    explicit ValueNodePayload();
    virtual ~ValueNodePayload();
};

#endif // VALUENODEPAYLOAD_HXX
