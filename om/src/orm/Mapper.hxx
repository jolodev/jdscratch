#ifndef MAPPER_HXX
#define MAPPER_HXX

#include <db/Database.hxx>
#include <db/Schema.hxx>
#include <db/Table.hxx>
#include <db/TableColumn.hxx>

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
        t->setIsAudited(true);

        auto o = std::unique_ptr<ObjectT>(new ObjectT());

        for (auto p : o->properties()) {
            (void) createColumn(t, p);
        }

        return t;
    }

    void createColumn(TableSP t, AbstractPropertySP p);
};

#endif // MAPPER_HXX
