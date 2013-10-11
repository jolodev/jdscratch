#include "InDatabaseNode.hxx"

#include <db/Database.hxx>

InDatabaseNode::InDatabaseNode(Database *db, const QString &n)
    : AbstractDbNode(), m_db(db), m_name(n)
{
}

InDatabaseNode::~InDatabaseNode()
{

}

Database *InDatabaseNode::database() const
{
    return static_cast<Database*>(parent());
}

QString InDatabaseNode::implName() const
{
    return m_name;
}

QString InDatabaseNode::implQualifiedName() const
{
    return m_name;
}

AbstractDbNode *InDatabaseNode::implParent() const
{
    return m_db;
}
