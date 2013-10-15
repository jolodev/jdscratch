#ifndef SCHEMAFWD_HXX
#define SCHEMAFWD_HXX

#include <Types.hxx>

class Schema;
typedef Schema* SchemaP;
typedef std::shared_ptr<Schema> SchemaSP;
typedef std::vector<SchemaSP> SchemaSPV;

#endif // SCHEMAFWD_HXX
