#ifndef EDGETYPES_HXX
#define EDGETYPES_HXX

#include <Types.hxx>

enum class EdgeTypes {
    Unknown,
    ParentChild,
    Reference
};

String edgeTypeToString(const EdgeTypes t);

#endif // EDGETYPES_HXX
