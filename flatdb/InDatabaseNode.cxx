#include "InDatabaseNode.hxx"

InDatabaseNode::InDatabaseNode(DatabaseP db, const Id& parentId, const Id& id, const QString& n, const QString& c)
    : Node<Database>(db, parentId, id, n, c)
{
}

InDatabaseNode::~InDatabaseNode()
{

}
