#include "Schema.hxx"

Schema::Schema(Database *db, const QString &n)
    : InDatabaseNode(db, n)
{
}

Schema::~Schema()
{

}
