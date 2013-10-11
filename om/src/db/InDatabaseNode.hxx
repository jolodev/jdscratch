#ifndef INDATABASENODE_HXX
#define INDATABASENODE_HXX

#include <db/AbstractDbNode.hxx>

class Database;

class InDatabaseNode : public AbstractDbNode
{
public:
    explicit InDatabaseNode(Database* db, const QString& n);
    virtual ~InDatabaseNode();

    Database* database() const;

protected:
    QString implName() const override;
    QString implQualifiedName() const override;
    AbstractDbNode* implParent() const override;

private:
    Database* m_db;
    QString m_name;
};

#endif // INDATABASENODE_HXX
