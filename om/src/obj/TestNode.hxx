#ifndef TESTNODE_HXX
#define TESTNODE_HXX

#include <obj/Object.hxx>

class TestNode : public Object
{
public:
    static QString singular();

    explicit TestNode(const QUuid& id);
    virtual ~TestNode();
};

#endif // TESTNODE_HXX