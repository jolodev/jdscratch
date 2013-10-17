#ifndef FOSSIL_HXX
#define FOSSIL_HXX

#include <ValueNodePayload.hxx>

class Fossil : public ValueNodePayload
{
public:
    static String singular();
    static String plural();

    explicit Fossil(AbstractNode* n = nullptr);
    virtual ~Fossil();
};

#endif // FOSSIL_HXX
