#include "RequestTypes.hxx"

using namespace EGraph;

String EGraph::requestTypeToString(const RequestTypes &t)
{
    switch(t) {
    case(RequestTypes::Select): return "SELECT";
    case(RequestTypes::Insert): return "INSERT";
    case(RequestTypes::Update): return "UPDATE";
    case(RequestTypes::Delete): return "DELETE";
    case(RequestTypes::Export): return "EXPORT";
    default: return "UNKNOWN";
    }
}
