#ifndef ABSTRACTFORMATER_HXX
#define ABSTRACTFORMATER_HXX

#include <egraph/Graph.hxx>
#include <egraph/Vertex.hxx>
#include <egraph/Edge.hxx>

#include "AbstractFormatDialect.hxx"

namespace EGraph {
class AbstractFormater
{
public:
    explicit AbstractFormater();
    virtual ~AbstractFormater();

    String present(VertexSP v, EdgeSPV in, EdgeSPV out);

protected:
    virtual AbstractFormatDialect* dialect() = 0;
};
}

#endif // ABSTRACTFORMATER_HXX
