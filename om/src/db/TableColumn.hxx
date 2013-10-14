#ifndef TABLECOLUMN_HXX
#define TABLECOLUMN_HXX

#include <db/InTableNode.hxx>

#include <obj/PropertyRole.hxx>

#include <db/TableColumnFwd.hxx>

class TableColumn : public InTableNode
{
public:
    explicit TableColumn(Table* t, const QString& n, const QString& tn=QString());
    virtual ~TableColumn();

    void setTypeName(const QString& n);
    QString typeName() const;

    void setRoles(const std::vector<PropertyRole> r);

    void setNotNull(bool nn);
    void setDefaultExpression(const QString& expr);
    bool hasRole(PropertyRole r) const;

    bool notNull() const;
    QString defaultExpression() const;

private:
    QString m_typeName;
    bool m_notNull { false };
    QString m_defaultExpression { "NULL" };
    std::vector<PropertyRole> m_roles;
};

#endif // TABLECOLUMN_HXX
