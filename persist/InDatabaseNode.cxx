#include "InDatabaseNode.hxx"

#include <Database.hxx>

InDatabaseNode::InDatabaseNode(AbstractNodeP p, const QString &n, const QString &c)
    : Node(p, n, c)
{
}

InDatabaseNode::~InDatabaseNode()
{

}

DatabaseP InDatabaseNode::database() const
{
    return static_cast<DatabaseP>(parent());
}
