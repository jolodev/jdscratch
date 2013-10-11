#ifndef INSCHEMANODE_HXX
#define INSCHEMANODE_HXX

#include <db/AbstractDbNode.hxx>

class Schema;

class InSchemaNode : public AbstractDbNode
{
public:
    explicit InSchemaNode(Schema* s, const QString& n);
    virtual ~InSchemaNode();

    Schema* schema() const;

protected:
    QString implName() const override;
    QString implQualifiedName() const override;
    AbstractDbNode* implParent() const override;

private:
    Schema* m_s { nullptr };
    QString m_name;
};

#endif // INSCHEMANODE_HXX
