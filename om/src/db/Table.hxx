#ifndef TABLE_HXX
#define TABLE_HXX

#include <db/InSchemaNode.hxx>

#include <db/TableFwd.hxx>
#include <db/TableColumnFwd.hxx>

#include <obj/PropertyRole.hxx>

class Table : public InSchemaNode
{
public:
    explicit Table(Schema* s, const QString& n);
    virtual ~Table();

    void setIsAudited(bool b);

    bool isAudited() const;

    TableColumnSP firstColumnWithRole(PropertyRole r);

private:
    bool m_isAudited { false };
};

#endif // TABLE_HXX
