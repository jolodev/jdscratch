#include "AbstractFormatDialect.hxx"

using namespace EGraph;

AbstractFormatDialect::AbstractFormatDialect()
{
}

AbstractFormatDialect::~AbstractFormatDialect()
{

}

String AbstractFormatDialect::present(VertexSP v, EdgeSPV in, EdgeSPV out) const
{
    return implPresent(v, in, out)   ;
}
