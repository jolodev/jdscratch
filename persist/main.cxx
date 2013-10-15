#include <Database.hxx>
#include <Schema.hxx>
#include <Table.hxx>

#include <Tools.hxx>

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    auto db = std::make_shared<Database>(Database("db", "demo db"));
    auto data = db->node<Schema>(Config::DataSchemaName);
    auto fossilTypes = data->createValueTable(Config::FossilTypesTableName, "");

    debug(std::cout, db);

    return EXIT_SUCCESS;
}
