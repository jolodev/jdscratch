#include <EdgeTypes.hxx>



String edgeTypeToString(const EdgeTypes t)
{
    switch(t) {
    case(EdgeTypes::ParentChild): return "Parent-Child";
    case(EdgeTypes::Reference): return "Reference";
    case(EdgeTypes::Unknown): return "Unknown";
    default: return "Undefined";
    }
}
