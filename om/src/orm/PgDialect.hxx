#ifndef PGDIALECT_HXX
#define PGDIALECT_HXX

#include <orm/AbstractDatabaseDialect.hxx>

class PgDialect : public AbstractDatabaseDialect
{
public:
    static QString name();

    explicit PgDialect();
    virtual ~PgDialect();

protected:
    void implCreate(SchemaSP s, QStringList& buf) const override;
    void implCreate(TableSP t, QStringList& buf) const override;
};

#endif // PGDIALECT_HXX
