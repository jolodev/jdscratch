#include <Tools.hxx>

#include <Database.hxx>
#include <Config.hxx>

#include <DbCreator.hxx>
#include <PostgresDialect.hxx>

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    auto db = std::make_shared<Database>(Database());
    db->createValueTable(Config::Tables::FossilTypes);
    db->createValueTable(Config::Tables::Fossils);
    db->debug();

    auto gen = DbCreator<PostgresDialect>();

    //std::cout << std::endl << "-- CREATE SCRIPT BEGIN " << gen.create(db).join("\n") << std::endl << "-- CREATE SCRIPT END";

    return EXIT_SUCCESS;
}
