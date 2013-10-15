#ifndef FOSSILTYPE_HXX
#define FOSSILTYPE_HXX

#include <ValueNodePayload.hxx>

class FossilType : public ValueNodePayload
{
public:
    static String singular();
    static String plural();

    explicit FossilType();
    virtual ~FossilType();
};

#endif // FOSSILTYPE_HXX
