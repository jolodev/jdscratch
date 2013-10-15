#ifndef TABLECOLUMN_HXX
#define TABLECOLUMN_HXX

#include <InTableNode.hxx>

#include <TableColumnFwd.hxx>
#include <DataTypeFwd.hxx>

class TableColumn : public InTableNode
{
public:
    static QString staticSingular();

    explicit TableColumn(AbstractNodeP p = nullptr, const QString& n = "", const QString& c = "");
    virtual ~TableColumn();

    void setDataType(DataTypeSP t);

    DataTypeSP dataType() const;

protected:
    QString implSingular() const override;

private:
    DataTypeSP m_type;
};

#endif // TABLECOLUMN_HXX
