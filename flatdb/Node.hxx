#ifndef NODE_HXX
#define NODE_HXX

#include <AbstractNode.hxx>

#include <Database.hxx>

template<typename ParentNodeT>
class Node : public AbstractNode
{
public:
    using ParentNodeType = ParentNodeT;

    explicit Node(DatabaseP db = nullptr,
                  const Id& parentId = createInvalidId(), const Id& id = createInvalidId(),
                  const QString& n = "", const QString& c = "")
        : AbstractNode(), m_db(db), m_parentId(parentId), m_id(id), m_name(n), m_comment(c) {}
    virtual ~Node() {}

    std::shared_ptr<ParentNodeType> parentNode() const { return database()->template nodeById<ParentNodeT>(parentId()); }

protected:
    virtual DatabaseP implDatabase() const override { return m_db; }

    virtual Id implParentId() const override { return m_parentId; }
    virtual Id implId() const override { return m_id; }
    virtual QString implName() const override { return m_name; }
    virtual QString implQualifiedName() const override {return name(); }
    virtual QString implComment() const override { return m_comment; }

    virtual QString implToString() const override { return QString("%1: %2").arg(singular()).arg(qualifiedName()); }

private:
    DatabaseP m_db { nullptr };
    Id m_parentId { createInvalidId() };
    Id m_id { createInvalidId() };
    QString m_name { "" };
    QString m_comment { "" };
};

#endif // NODE_HXX
