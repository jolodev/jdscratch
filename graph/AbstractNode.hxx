#ifndef ABSTRACTNODE_HXX
#define ABSTRACTNODE_HXX

#include <Types.hxx>

class Graph;

class AbstractNode
{
public:
    explicit AbstractNode();
    virtual ~AbstractNode();

    String toString() const;

    Graph* graph() const;
    Id id() const;

protected:
    virtual Id implId() const = 0;
    virtual Graph* implGraph() const = 0;
    virtual String implToString() const = 0;
};

#endif // ABSTRACTNODE_HXX
