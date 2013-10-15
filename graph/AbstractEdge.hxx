#ifndef ABSTRACTEDGE_HXX
#define ABSTRACTEDGE_HXX

#include <Types.hxx>

#include <EdgeTypes.hxx>

class AbstractNode;
typedef std::shared_ptr<AbstractNode> AbstractNodeSP;

class AbstractEdge
{
public:
    explicit AbstractEdge();
    virtual ~AbstractEdge();

    AbstractNodeSP left() const;
    AbstractNodeSP right() const;

    void setLeft(AbstractNodeSP l);
    void setRight(AbstractNodeSP r);

    void set(AbstractNodeSP l, AbstractNodeSP r);

    String toString() const;

    Id id() const;
    EdgeTypes edgeType() const;

protected:
    virtual EdgeTypes implEdgeType() const = 0;
    virtual Id implId() const = 0;

    virtual AbstractNodeSP implLeft() const = 0;
    virtual AbstractNodeSP implRight() const = 0;

    virtual void implSetLeft(AbstractNodeSP l) = 0;
    virtual void implSetRight(AbstractNodeSP r) = 0;

    virtual String implToString() const;
};

#endif // ABSTRACTEDGE_HXX
