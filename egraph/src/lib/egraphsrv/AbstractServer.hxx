#ifndef ABSTRACTSERVER_HXX
#define ABSTRACTSERVER_HXX

#include <egraph/Global.hxx>

#include <egraph/GraphFwd.hxx>
#include <egraph/VertexFwd.hxx>
#include <egraph/EdgeFwd.hxx>

namespace EGraph {
class AbstractFormatDialect;

class AbstractServer
{
public:
    explicit AbstractServer();
    virtual ~AbstractServer();

    void setGraph(GraphSP g);
    GraphSP graph() const;

    String present(VertexSP v);

protected:
    virtual String implPresent(VertexSP v);

    virtual void implSetGraph(GraphSP g) = 0;
    virtual GraphSP implGraph() const = 0;
    virtual AbstractFormatDialect* dialect() = 0;
};
}

#endif // ABSTRACTSERVER_HXX
