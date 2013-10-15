#include "Schema.hxx"

QString Schema::staticSingular()
{
    return "SCHEMA";
}

QString Schema::staticPlural()
{
    return "SCHEMATA";
}

Schema::Schema(DatabaseP db, const Id &parentId, const Id &id, const QString &n, const QString &c)
    : InDatabaseNode(db, parentId, id, n, c)
{
}

Schema::~Schema()
{

}

QString Schema::implSingular() const
{
    return Schema::staticSingular();
}

QString Schema::implPlural() const
{
    return Schema::staticPlural();
}
