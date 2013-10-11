#ifndef TABLE_HXX
#define TABLE_HXX

#include <db/InSchemaNode.hxx>

#include <db/TableFwd.hxx>

class Table : public InSchemaNode
{
public:
    explicit Table(Schema* s, const QString& n);
    virtual ~Table();
};

#endif // TABLE_HXX
