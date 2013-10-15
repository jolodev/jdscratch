#include "Extension.hxx"

QString Extension::staticSingular()
{
    return "EXTENSION";
}

Extension::Extension(AbstractNodeP p, const QString &n, const QString &c)
    : InSchemaNode(p, n, c)
{
}

Extension::~Extension()
{

}

QString Extension::implSingular() const
{
    return Extension::staticSingular();
}
