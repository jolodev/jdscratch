#ifndef COLUMNROLES_HXX
#define COLUMNROLES_HXX

#include <Types.hxx>

enum class ColumnRoles
{
    Unknown,
    PrimaryKey,
    Version,
    Creator,
    Creation,
    Modificator,
    Modification,
    ForeignKey,
    LabelValue,
    Value
};

QString roleToString(ColumnRoles r);

#endif // COLUMNROLES_HXX
