#ifndef INSCHEMANODE_HXX
#define INSCHEMANODE_HXX

#include <Node.hxx>

#include <Schema.hxx>

class InSchemaNode : public Node<Schema>
{
public:
    InSchemaNode(DatabaseP db = nullptr, const Id& parentId = Id(), const Id& id = Id(), const QString& n = "", const QString& c = "");
    virtual ~InSchemaNode();

protected:
    QString implQualifiedName() const override;
};

#endif // INSCHEMANODE_HXX
