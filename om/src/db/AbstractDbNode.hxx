#ifndef ABSTRACTDBNODE_HXX
#define ABSTRACTDBNODE_HXX

#include <core/Types.hxx>

#include <db/AbstractDbNodeFwd.hxx>

class AbstractDbNode
{
public:
    explicit AbstractDbNode();
    virtual ~AbstractDbNode();

    AbstractDbNode* parent() const;
    QString name() const;
    QString qualifiedName() const;

    QString makeIdentifier(const QString& n);

    template<typename NodeT>
    std::vector<std::shared_ptr<NodeT> > nodes() const {
        auto r = std::vector<std::shared_ptr<NodeT> >();

        for (auto n : m_nodesV) {
            auto tmp = std::dynamic_pointer_cast<NodeT>(n);

            if (tmp) {
                r.push_back(tmp);
            }
        }

        return r;
    }

    template<typename NodeT, typename ParentNodeT>
    std::shared_ptr<NodeT> create(std::shared_ptr<ParentNodeT> p, const QString& n) {
        return create<NodeT>(p.get(), n);
    }

    template<typename NodeT, typename ParentNodeT>
    std::shared_ptr<NodeT> create(ParentNodeT* p, const QString& n) {
        auto c = std::make_shared<NodeT>(p, n);
        registerNode(c);
        return c;
    }

    template<typename NodeT>
    std::shared_ptr<NodeT> node(const QString& n) {
        auto i = m_nodesM.find(n);

        assert(m_nodesM.end() != i);

        return std::static_pointer_cast<NodeT>((*i).second);
    }

protected:
    void registerNode(AbstractDbNodeSP n);

    virtual AbstractDbNode* implParent() const = 0;
    virtual QString implName() const = 0;
    virtual QString implQualifiedName() const = 0;

    AbstractDbNodeSPV m_nodesV;
    AbstractDbNodeSPM m_nodesM;

};

#endif // ABSTRACTDBNODE_HXX
