#ifndef TABLE_HXX
#define TABLE_HXX

#include <InSchemaNode.hxx>

#include <TableFwd.hxx>
#include <TableColumnFwd.hxx>
#include <ColumnRoles.hxx>

class Table : public InSchemaNode
{
public:
    static QString staticSingular();
    static QString staticPlural();

    explicit Table(DatabaseP db = nullptr, const Id& parentId = Id(), const Id& id = Id(), const QString& n = "", const QString& c = "");
    virtual ~Table();

    TableColumnSP createColumn(const QString& n, const QString& typeN, ColumnRoles r = ColumnRoles::Value, const QString& c = "");

protected:
    QString implSingular() const override;
    QString implPlural() const override;
};

#endif // TABLE_HXX
