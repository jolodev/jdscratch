#ifndef INTABLENODE_HXX
#define INTABLENODE_HXX

#include <db/AbstractDbNode.hxx>

#include <db/TableFwd.hxx>

class InTableNode : public AbstractDbNode
{
public:
    explicit InTableNode(Table* t, const QString& n);
    virtual ~InTableNode();

    Table* table() const;

protected:
    QString implName() const override;
    QString implQualifiedName() const override;
    AbstractDbNodeRP implParent() const override;

private:
    Table* m_t;
    QString m_name;
};

#endif // INTABLENODE_HXX
