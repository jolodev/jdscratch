#ifndef INDATABASENODE_HXX
#define INDATABASENODE_HXX

#include <Node.hxx>

#include <Database.hxx>

class InDatabaseNode : public Node<Database>
{
public:
    explicit InDatabaseNode(DatabaseP db = nullptr, const Id& parentId = Id(),
                            const Id& id = Id(), const QString& n = "", const QString& c = "");
    virtual ~InDatabaseNode();
};

#endif // INDATABASENODE_HXX
