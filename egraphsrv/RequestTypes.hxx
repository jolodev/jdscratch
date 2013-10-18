#ifndef REQUESTTYPES_HXX
#define REQUESTTYPES_HXX

#include <Global.hxx>

namespace EGraph {
enum class RequestTypes {
    Select,
    Insert,
    Update,
    Delete,
    Export
};

String requestTypeToString(const RequestTypes& t);
}

#endif // REQUESTTYPES_HXX
