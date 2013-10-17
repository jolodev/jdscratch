#ifndef EDGEROLES_HXX
#define EDGEROLES_HXX

#include <Global.hxx>

enum class EdgeRoles
{
    Unspecified,
    IsSubType,
    IsSuperType,
    IsPartOf,
    Contains
};

String edgeRoleToString(EdgeRoles r);

std::ostream& operator<<(std::ostream& strm, const EdgeRoles& r);

#endif // EDGEROLES_HXX
