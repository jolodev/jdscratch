#ifndef GRAPH_HXX
#define GRAPH_HXX

#include <Types.hxx>

#include <Node.hxx>
#include <Edge.hxx>

typedef std::shared_ptr<AbstractNode> AbstractNodeSP;
typedef std::shared_ptr<AbstractEdge> AbstractEdgeSP;

typedef std::vector<AbstractNodeSP> AbstractNodeSPV;
typedef std::vector<AbstractEdgeSP> AbstractEdgeSPV;

class Graph
{
public:
    explicit Graph();
    virtual ~Graph();

    void printOn(std::ostream& strm) const;
    void printEdgesWithLeftNode(AbstractNodeSP n, std::ostream& strm) const;
    void printEdgesWithRightNode(AbstractNodeSP n, std::ostream& strm) const;

    AbstractEdgeSP createEdge(EdgeTypes t, AbstractNodeSP l, AbstractNodeSP r);

    const AbstractNodeSPV nodes() const { return m_nodes; }
    const AbstractEdgeSPV edges() const { return m_edges; }

    AbstractEdgeSPV edgesWithLeft(AbstractNodeSP n) const {
        auto r = AbstractEdgeSPV();

        for (auto e : edges()) {
            if (e->left() == n) {
                r.push_back(e);
            }
        }
        return r;
    }

    AbstractEdgeSPV edgesWithRight(AbstractNodeSP n) const {
        auto r = AbstractEdgeSPV();

        for (auto e : edges()) {
            if (e->right() == n) {
                r.push_back(e);
            }
        }
        return r;
    }

    template<typename PayloadT>
    void printTypedNodes(std::ostream& strm) const {
        strm << std::endl << "== BEGIN OF " << PayloadT::plural() << " ==";
        for (auto n : typedNodes<PayloadT>()) {
            strm << std::endl << n->toString();
        }
        strm << std::endl << "== END OF " << PayloadT::plural() << " ==";
    }

    template<typename PayloadT>
    std::vector<std::shared_ptr<Node<PayloadT> > > typedNodes() const {
        auto r = std::vector<std::shared_ptr<Node<PayloadT> > >();

        for (auto n : nodes()) {
            auto tmp = std::dynamic_pointer_cast<Node<PayloadT> >(n);

            if (tmp) {
                r.push_back(tmp);
            }
        }

        return r;
    }

    template<typename PayloadT>
    std::shared_ptr<Node<PayloadT> > createNode() {
        auto n = std::make_shared<Node<PayloadT> >(Node<PayloadT>(this));
        m_nodes.push_back(n);
        return n;
    }

private:
    AbstractNodeSPV m_nodes;
    AbstractEdgeSPV m_edges;
};

#endif // GRAPH_HXX
