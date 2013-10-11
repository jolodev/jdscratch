#include "InSchemaNode.hxx"

#include <db/Schema.hxx>

InSchemaNode::InSchemaNode(Schema *s, const QString &n)
    : AbstractDbNode(), m_s(s), m_name(n)
{
}

InSchemaNode::~InSchemaNode()
{

}

Schema *InSchemaNode::schema() const
{
    return static_cast<Schema*>(parent());
}

QString InSchemaNode::implName() const
{
    return m_name;
}

QString InSchemaNode::implQualifiedName() const
{
    return schema()->name() + "." + name();
}

AbstractDbNode *InSchemaNode::implParent() const
{
    return m_s;
}
