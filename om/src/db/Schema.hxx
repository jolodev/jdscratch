#ifndef SCHEMA_HXX
#define SCHEMA_HXX

#include <db/InDatabaseNode.hxx>

class Schema : public InDatabaseNode
{
public:
    explicit Schema(Database* db, const QString& n);
    virtual ~Schema();
};

#endif // SCHEMA_HXX
