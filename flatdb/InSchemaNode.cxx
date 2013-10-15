#include "InSchemaNode.hxx"

#include <Database.hxx>
#include <Schema.hxx>

InSchemaNode::InSchemaNode(DatabaseP db, const Id &parentId, const Id &id, const QString &n, const QString &c)
    : Node<Schema>(db, parentId, id, n, c)
{
}

InSchemaNode::~InSchemaNode()
{

}

QString InSchemaNode::implQualifiedName() const
{
    return QString("%1.%2").arg(parentNode()->name()).arg(name());
}
