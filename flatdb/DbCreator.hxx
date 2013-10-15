#ifndef DBCREATOR_HXX
#define DBCREATOR_HXX

#include <AbstractDbCreator.hxx>

template<typename SqlDialectT>
class DbCreator: public AbstractDbCreator {
public:
    explicit DbCreator(): AbstractDbCreator() {}
    virtual ~DbCreator() {}

protected:
    virtual QStringList implCreate(DatabaseSP db) {
        QStringList buf;

        auto gen = SqlDialectT();

        gen.create(db, buf);

        return buf;
    }
};

#endif // DBCREATOR_HXX
