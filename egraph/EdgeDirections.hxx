#ifndef EDGEDIRECTIONS_HXX
#define EDGEDIRECTIONS_HXX

#include <Global.hxx>

enum class EdgeDirections {
    In,
    Out,
    InOut
};

String edgeDirectionToString(EdgeDirections d);

std::ostream& operator<<(std::ostream& strm, const EdgeDirections& d);

#endif // EDGEDIRECTIONS_HXX
