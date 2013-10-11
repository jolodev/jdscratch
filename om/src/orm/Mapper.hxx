#ifndef MAPPER_HXX
#define MAPPER_HXX

#include <db/Database.hxx>
#include <db/Schema.hxx>
#include <db/Table.hxx>

#include <obj/AbstractObject.hxx>

class Mapper
{
public:
    explicit Mapper();
    virtual ~Mapper();

    static Mapper* instance();

    template<typename ObjectT>
    TableSP createDataTableIn(Database* targetDb) {
        auto t = targetDb->node<Schema>(Database::dataSchemaName())->create<Table, Schema>(targetDb->node<Schema>(Database::dataSchemaName()),
                                                                                           targetDb->makeIdentifier(ObjectT::plural()));
        return t;
    }
};

#endif // MAPPER_HXX
