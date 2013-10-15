#ifndef ABSTRACTNODEPAYLOAD_HXX
#define ABSTRACTNODEPAYLOAD_HXX

#include <Types.hxx>

class AbstractNode;

class AbstractNodePayload
{
public:
    explicit AbstractNodePayload();
    virtual ~AbstractNodePayload();

    String toString() const;

    void setName(const String& n);
    void setComment(const String& c);

    String name() const;
    String comment() const;

    AbstractNode* node() const;

protected:
    virtual AbstractNode* implNode() const = 0;

    virtual String implToString() const;

    virtual void implSetName(const String& n) = 0;
    virtual void implSetComment(const String& c) = 0;

    virtual String implName() const = 0;
    virtual String implComment() const = 0;
};

#endif // ABSTRACTNODEPAYLOAD_HXX
