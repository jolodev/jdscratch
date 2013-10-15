#ifndef TABLEFWD_HXX
#define TABLEFWD_HXX

#include <Types.hxx>

class Table;
typedef Table* TableP;
typedef std::shared_ptr<Table> TableSP;
typedef std::vector<TableSP> TableSPV;

#endif // TABLEFWD_HXX
