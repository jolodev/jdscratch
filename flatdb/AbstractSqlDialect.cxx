#include "AbstractSqlDialect.hxx"

#include <Database.hxx>
#include <DataType.hxx>
#include <Schema.hxx>
#include <Table.hxx>
#include <TableColumn.hxx>
#include <Extension.hxx>

AbstractSqlDialect::AbstractSqlDialect()
{
}

AbstractSqlDialect::~AbstractSqlDialect()
{

}

void AbstractSqlDialect::create(DatabaseSP db, QStringList &buf) const
{
    create(db->nodes<Schema>(), buf);

    for (auto s : db->nodes<Schema>()) {
        create(db->childNodes<Extension>(s), buf);
    }

    for (auto s : db->nodes<Schema>()) {
        create(db->childNodes<Table>(s), buf);
    }

}

void AbstractSqlDialect::create(const SchemaSPV &s, QStringList &buf) const
{
    for (auto i : s) {
        implCreate(i, buf);
    }
}

void AbstractSqlDialect::create(const ExtensionSPV &e, QStringList &buf) const
{
    for (auto i : e) {
        implCreate(i, buf);
    }
}

void AbstractSqlDialect::create(const TableSPV &t, QStringList &buf) const
{
    for (auto i : t) {
        implCreate(i, buf);
    }
}
