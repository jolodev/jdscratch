#ifndef NODE_HXX
#define NODE_HXX

#include <AbstractNode.hxx>

#include <NodeFwd.hxx>

class Node : public AbstractNode
{
public:
    explicit Node(AbstractNodeP p = nullptr, const QString& n = "", const QString& c = "");
    virtual ~Node();

protected:
    void registerChild(AbstractNodeSP c) override;
    const AbstractNodeSPV& implChildNodes() const;
    AbstractNodeP implParent() const override;
    QString implName() const override;
    QString implComment() const override;
    QString implToString() const override;

private:
    AbstractNodeP m_parent { nullptr };
    QString m_name { "" };
    QString m_comment { "" };
    AbstractNodeSPV m_children { AbstractNodeSPV() };
};

#endif // NODE_HXX
