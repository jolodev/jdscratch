#ifndef DBGEN_HXX
#define DBGEN_HXX

#include <orm/AbstractDbGen.hxx>

template<typename DialectT>
class DbGen: public AbstractDbGen {
public:
    using Dialect = DialectT;

    explicit DbGen()
        : AbstractDbGen() {}

    virtual ~DbGen() {
        delete m_d;
    }

protected:
    QStringList implCreate(Database* db) const override {
        assert(nullptr != db);

        auto buf = QStringList();
        //buf.append(comment(QObject::tr("Creating for dialect: %1").arg(Dialect::name())));

        // drop existing schema
        for (auto s : db->nodes<Schema>()) {
            m_d->drop(s, buf);
        }

        // create schemata
        for (auto s : db->nodes<Schema>()) {
            m_d->create(s, buf);
        }

        // create tables
        for (auto s : db->nodes<Schema>()) {
            for (auto t : s->nodes<Table>()) {
                m_d->create(t, buf);
            }
        }
        return buf;
    }

private:
    Dialect* m_d { new Dialect() };
};

#endif // DBGEN_HXX
