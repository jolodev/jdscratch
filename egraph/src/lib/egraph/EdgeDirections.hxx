#ifndef EDGEDIRECTIONS_HXX
#define EDGEDIRECTIONS_HXX

#include "Global.hxx"

namespace EGraph {
enum class EdgeDirections {
    In,
    Out,
    InOut
};

String edgeDirectionToString(EdgeDirections d);
}

std::ostream& operator<<(std::ostream& strm, const EGraph::EdgeDirections& d);

#endif // EDGEDIRECTIONS_HXX
