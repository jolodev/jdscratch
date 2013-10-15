#include "InTableNode.hxx"

#include <Table.hxx>
#include <Schema.hxx>
#include <Database.hxx>

InTableNode::InTableNode(DatabaseP db, const Id &parentId, const Id &id, const QString &n, const QString &c)
    : Node<Table>(db, parentId, id, n, c)
{
}

InTableNode::~InTableNode()
{

}

QString InTableNode::implQualifiedName() const
{
    return QString("%1.%2").arg(parentNode()->qualifiedName()).arg(name());
}
