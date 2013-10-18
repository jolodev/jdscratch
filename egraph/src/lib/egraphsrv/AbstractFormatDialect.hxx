#ifndef ABSTRACTFORMATDIALECT_HXX
#define ABSTRACTFORMATDIALECT_HXX

#include <egraph/Global.hxx>

#include <egraph/VertexFwd.hxx>
#include <egraph/EdgeFwd.hxx>

namespace EGraph {
class AbstractFormatDialect
{
public:
    explicit AbstractFormatDialect();
    virtual ~AbstractFormatDialect();

    String present(VertexSP v, EdgeSPV in, EdgeSPV out) const;

protected:
    virtual String implPresent(VertexSP v, EdgeSPV in, EdgeSPV out) const = 0;
};
}

#endif // ABSTRACTFORMATDIALECT_HXX
