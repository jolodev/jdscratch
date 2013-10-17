#include "EdgeRoles.hxx"


String edgeRoleToString(EdgeRoles r)
{
    switch(r) {
    case(EdgeRoles::Unspecified): return "Unspecified";
    case(EdgeRoles::IsSubType): return "Is Sub Type";
    case(EdgeRoles::IsSuperType): return "Is Super Type";
    case(EdgeRoles::IsPartOf): return "Is Part Of";
    default: return "Unknown";
    }
}


std::ostream &operator<<(std::ostream &strm, const EdgeRoles &r)
{
    strm << edgeRoleToString(r);
    return strm;
}
