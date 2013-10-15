#ifndef NODE_HXX
#define NODE_HXX

#include <AbstractNode.hxx>

#include <Tools.hxx>

template<typename PayloadT>
class Node: public AbstractNode {
public:
    static String singular() { return PayloadT::singular(); }

    using PayloadType = PayloadT;

    explicit Node(Graph* g = nullptr): AbstractNode(), m_id(createNodeId()), m_g(g), m_d(std::make_shared<PayloadT>(PayloadT())) {}
    virtual ~Node() { }

    std::shared_ptr<PayloadT> data() const { return m_d; }

protected:
    virtual Id implId() const override { return m_id; }
    virtual Graph* implGraph() const override { return m_g; }

    virtual String implToString() const override {
        StringStream s;
        s << PayloadT::singular() << " [" << id() << "]: " << data()->toString();
        return s.str();
    }

private:
    Id m_id { invalidId() };
    Graph* m_g { nullptr };
    std::shared_ptr<PayloadT> m_d;
};

#endif // NODE_HXX
