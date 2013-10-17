#include <EdgeDirections.hxx>

String edgeDirectionToString(EdgeDirections d)
{
    switch (d) {
    case(EdgeDirections::In): return "IN";
    case(EdgeDirections::Out): return "OUT";
    case(EdgeDirections::InOut): return "IN OUT";
    default: return "??";
    }
}

std::ostream &operator<<(std::ostream &strm, const EdgeDirections &d)
{
    strm << edgeDirectionToString(d);
    return strm;
}
