#include "AbstractFormater.hxx"

using namespace EGraph;

AbstractFormater::AbstractFormater()
{
}

AbstractFormater::~AbstractFormater()
{
}

String AbstractFormater::present(VertexSP v, EdgeSPV in, EdgeSPV out)
{
    return dialect()->present(v, in, out);
}
