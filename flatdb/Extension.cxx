#include "Extension.hxx"

QString Extension::staticSingular()
{
    return "EXTENSION";
}

QString Extension::staticPlural()
{
    return "EXTENSIONS";
}

Extension::Extension(DatabaseP db, const Id &parentId, const Id &id, const QString &n, const QString &c)
    : InSchemaNode(db, parentId, id, n, c)
{
}

Extension::~Extension()
{

}

QString Extension::implSingular() const
{
    return Extension::staticSingular();
}

QString Extension::implPlural() const
{
    return Extension::staticPlural();
}
