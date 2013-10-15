#ifndef ABSTRACTDBCREATOR_HXX
#define ABSTRACTDBCREATOR_HXX

#include <Types.hxx>

#include <DatabaseFwd.hxx>

class AbstractDbCreator
{
public:
    explicit AbstractDbCreator();
    virtual ~AbstractDbCreator();

    QStringList create(DatabaseSP db);

protected:
    virtual QStringList implCreate(DatabaseSP db) = 0;
};

#endif // ABSTRACTDBCREATOR_HXX
