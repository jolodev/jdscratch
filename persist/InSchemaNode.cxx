#include "InSchemaNode.hxx"

#include <Schema.hxx>

InSchemaNode::InSchemaNode(AbstractNodeP p, const QString &n, const QString &c)
    : Node(p, n, c)
{
}

InSchemaNode::~InSchemaNode()
{

}

SchemaP InSchemaNode::schema() const
{
    return dynamic_cast<SchemaP>(parent());
}
