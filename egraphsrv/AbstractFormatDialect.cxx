#include "AbstractFormatDialect.hxx"

using namespace EGraph;

AbstractFormatDialect::AbstractFormatDialect()
{
}

AbstractFormatDialect::~AbstractFormatDialect()
{

}

String AbstractFormatDialect::present(VertexSP v) const
{
    return implPresent(v);
}
