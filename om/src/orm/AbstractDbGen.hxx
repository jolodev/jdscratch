#ifndef ABSTRACTDBGEN_HXX
#define ABSTRACTDBGEN_HXX

#include <core/Types.hxx>

#include <db/DatabaseFwd.hxx>
#include <db/SchemaFwd.hxx>
#include <db/TableFwd.hxx>

class AbstractDbGen
{
public:
    explicit AbstractDbGen();
    virtual ~AbstractDbGen();

    QStringList create(Database* db) const;

protected:
    virtual QStringList implCreate(Database* db) const = 0;

    QString comment(const QString& txt) const;
};

#endif // ABSTRACTDBGEN_HXX
