#ifndef INTABLENODE_HXX
#define INTABLENODE_HXX

#include <Node.hxx>

#include <Table.hxx>

class InTableNode : public Node<Table>
{
public:
    explicit InTableNode(DatabaseP db = nullptr, const Id& parentId = Id(), const Id& id = Id(), const QString& n = "", const QString& c = "");
    virtual ~InTableNode();

protected:
    QString implQualifiedName() const override;
};

#endif // INTABLENODE_HXX
