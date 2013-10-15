#ifndef POSTGRESDIALECT_HXX
#define POSTGRESDIALECT_HXX

#include <AbstractSqlDialect.hxx>

class PostgresDialect: public AbstractSqlDialect {
public:
    explicit PostgresDialect();
    virtual ~PostgresDialect();

protected:
    virtual void implCreate(const SchemaSP& s, QStringList& buf) const;
    virtual void implCreate(const ExtensionSP& e, QStringList& buf) const;
    virtual void implCreate(const TableSP& t, QStringList& buf) const;
};

#endif // POSTGRESDIALECT_HXX
