#ifndef ABSTRACTNODE_HXX
#define ABSTRACTNODE_HXX

#include <AbstractNodeFwd.hxx>

#include <Config.hxx>

class AbstractNode
{
public:
    explicit AbstractNode();
    virtual ~AbstractNode();

    QString toString() const;
    QString singular() const;

    AbstractNodeP parent() const;
    QString name() const;
    QString comment() const;

    const AbstractNodeSPV& childNodes() const;

    template<typename NodeT>
    std::shared_ptr<NodeT> createNode(const QString& n, const QString& c = "") {
        auto tmp = std::make_shared<NodeT>(NodeT(this, n, c));
        registerChild(tmp);
        return tmp;
    }

    template<typename NodeT>
    const std::vector<std::shared_ptr<NodeT> > typedNodes() const {
        auto r = std::vector<std::shared_ptr<NodeT> >();

        for (auto c : childNodes()) {
            auto tmp = std::dynamic_pointer_cast<NodeT>(c);

            if (tmp) {
                r.push_back(tmp);
            }
        }

        return r;
    }

    template<typename NodeT>
    std::shared_ptr<NodeT> node(const QString& n) const {
        for (auto c : typedNodes<NodeT>()) {
            if (c->name() == n) {
                return c;
            }
        }

        return std::shared_ptr<NodeT>();
    }

protected:
    virtual void registerChild(AbstractNodeSP c) = 0;
    virtual const AbstractNodeSPV& implChildNodes() const = 0;
    virtual AbstractNodeP implParent() const = 0;
    virtual QString implToString() const = 0;
    virtual QString implSingular() const = 0;
    virtual QString implName() const = 0;
    virtual QString implComment() const = 0;
};

#endif // ABSTRACTNODE_HXX
