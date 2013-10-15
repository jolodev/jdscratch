#ifndef TABLECOLUMN_HXX
#define TABLECOLUMN_HXX

#include <InTableNode.hxx>

#include <TableColumnFwd.hxx>
#include <DataTypeFwd.hxx>
#include <ColumnRoles.hxx>

class TableColumn : public InTableNode
{
public:
    static QString staticSingular();
    static QString staticPlural();

    explicit TableColumn(DatabaseP db = nullptr, const Id& parentId = Id(), const Id& id = Id(), const QString& n = "", const QString& c = "");
    virtual ~TableColumn();

    void setDataType(DataTypeSP t);
    void setRole(ColumnRoles r);

    DataTypeSP dataType() const;
    ColumnRoles role() const;

protected:
    QString implToString() const override;
    QString implSingular() const override;
    QString implPlural() const override;

private:
    DataTypeSP m_dataType { DataTypeSP() };
    ColumnRoles m_role { ColumnRoles::Unknown };
};

#endif // TABLECOLUMN_HXX
