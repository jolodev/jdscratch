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
    void implDrop(SchemaSP s, QStringList& buf) const override;

private:
    void createAuditTableFor(TableSP t, QStringList& buf) const;
    void createAuditTriggerFor(TableSP dataT, QStringList& buf) const;
    void createVersioningTriggerFor(TableSP dataT, QStringList& buf) const;
};

#endif // PGDIALECT_HXX
