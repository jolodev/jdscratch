#ifndef INDATABASENODE_HXX
#define INDATABASENODE_HXX

#include <Node.hxx>

#include <DatabaseFwd.hxx>

class InDatabaseNode : public Node
{
public:
    explicit InDatabaseNode(AbstractNodeP p = nullptr, const QString& n="", const QString& c="");
    virtual ~InDatabaseNode();

    DatabaseP database() const;
};

#endif // INDATABASENODE_HXX
