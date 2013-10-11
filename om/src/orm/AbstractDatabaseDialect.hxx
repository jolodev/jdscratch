#ifndef ABSTRACTDATABASEDIALECT_HXX
#define ABSTRACTDATABASEDIALECT_HXX

#include <core/Types.hxx>

#include <db/SchemaFwd.hxx>
#include <db/TableFwd.hxx>

class AbstractDatabaseDialect
{
public:
    explicit AbstractDatabaseDialect();
    virtual ~AbstractDatabaseDialect();

    void create(SchemaSP s, QStringList& buf) const;
    void create(TableSP t, QStringList& buf) const;

protected:
    QString command(const QString& c) const;

    virtual void implCreate(SchemaSP s, QStringList& buf) const = 0;
    virtual void implCreate(TableSP t, QStringList& buf) const = 0;
};

#endif // ABSTRACTDATABASEDIALECT_HXX
