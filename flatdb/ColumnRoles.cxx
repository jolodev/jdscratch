#include "ColumnRoles.hxx"


QString roleToString(ColumnRoles r)
{
    switch(r) {
    case(ColumnRoles::Unknown): return QObject::tr("Unknown");
    case(ColumnRoles::PrimaryKey): return QObject::tr("Primary Key");
    case(ColumnRoles::ForeignKey): return QObject::tr("Foreign Key");
    case(ColumnRoles::Version): return QObject::tr("Version");
    case(ColumnRoles::Creator): return QObject::tr("Creator");
    case(ColumnRoles::Creation): return QObject::tr("Creation Timestamp");
    case(ColumnRoles::Modificator): return QObject::tr("Modificator");
    case(ColumnRoles::Modification): return QObject::tr("Modification Timestamp");
    case(ColumnRoles::Value): return QObject::tr("Value");
    case(ColumnRoles::LabelValue): return QObject::tr("Label Value");
    default: return QObject::tr("Undefined");
    }
}
