#ifndef INSCHEMANODE_HXX
#define INSCHEMANODE_HXX

#include <Node.hxx>

#include <SchemaFwd.hxx>

class InSchemaNode : public Node
{
public:
    explicit InSchemaNode(AbstractNodeP p = nullptr, const QString& n = "", const QString& c = "");
    virtual ~InSchemaNode();

    SchemaP schema() const;
};

#endif // INSCHEMANODE_HXX
