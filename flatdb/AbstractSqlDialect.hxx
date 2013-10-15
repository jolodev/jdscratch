#ifndef ABSTRACTSQLDIALECT_HXX
#define ABSTRACTSQLDIALECT_HXX

#include <Types.hxx>

#include <DatabaseFwd.hxx>
#include <SchemaFwd.hxx>
#include <TableFwd.hxx>
#include <TableColumn.hxx>
#include <DataTypeFwd.hxx>
#include <ExtensionFwd.hxx>

class AbstractSqlDialect
{
public:
    explicit AbstractSqlDialect();
    virtual ~AbstractSqlDialect();

    void create(DatabaseSP db, QStringList& buf) const;
    void create(const SchemaSPV& s, QStringList& buf) const;
    void create(const ExtensionSPV& e, QStringList& buf) const;
    void create(const TableSPV& t, QStringList& buf) const;

protected:
    virtual void implCreate(const SchemaSP& s, QStringList& buf) const = 0;
    virtual void implCreate(const ExtensionSP& e, QStringList& buf) const = 0;
    virtual void implCreate(const TableSP& t, QStringList& buf) const = 0;
};

#endif // ABSTRACTSQLDIALECT_HXX
