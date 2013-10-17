#include <EdgeDirections.hxx>

using namespace EGraph;

String EGraph::edgeDirectionToString(EdgeDirections d)
{
    switch (d) {
    case(EdgeDirections::In): return "IN";
    case(EdgeDirections::Out): return "OUT";
    case(EdgeDirections::InOut): return "IN OUT";
    default: return "??";
    }
}

std::ostream &operator<<(std::ostream &strm, const EGraph::EdgeDirections &d)
{
    strm << EGraph::edgeDirectionToString(d);
    return strm;
}
