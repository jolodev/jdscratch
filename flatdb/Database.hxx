#ifndef DATABASE_HXX
#define DATABASE_HXX

#include <Types.hxx>

#include <AbstractNode.hxx>
#include <Tools.hxx>
#include <Node.hxx>

#include <DatabaseFwd.hxx>
#include <TableFwd.hxx>

class Database
{
public:
    explicit Database();
    virtual ~Database();

    void debug();

    template<typename NodeT>
    std::shared_ptr<NodeT> createNode(const QString& n, const Id& parentId = createInvalidId(), const QString& c = "") {
        auto tmp = std::make_shared<NodeT>(NodeT(this, parentId, createId(), n, c));
        registerNode(tmp);
        return tmp;
    }

    template<typename NodeT>
    std::vector<std::shared_ptr<NodeT> > nodes() const {
        auto r = std::vector<std::shared_ptr<NodeT> >();

        for (auto n : m_nodeV) {
            auto tmp = std::dynamic_pointer_cast<NodeT>(n);

            if (tmp) {
                r.push_back(tmp);
            }
        }

        return r;
    }

    template<typename NodeT>
    std::vector<std::shared_ptr<NodeT> > childNodes(AbstractNodeSP p) const {
        auto r = std::vector<std::shared_ptr<NodeT> >();

        for (auto n : nodes<NodeT>()) {
            if (n->parentId() == p->id()) {
                r.push_back(n);
            }
        }

        return r;
    }

    template<typename NodeT>
    std::shared_ptr<NodeT> nodeById(const Id& id) const {
        std::cout << std::endl << "looking for node with ID " << id << "... ";

        auto i = m_nodeM.find(id);

        if (m_nodeM.end() == i) {
            std::cout << "not found." << std::endl;

            throw std::runtime_error(QString("Node with ID '%1'' not found in database").arg(id).toStdString().c_str());
            //Id std::runtime_error(QString("Node with ID '%1'' not found in database").arg(id.toString()).toStdString().c_str());
        }

        std::cout << "got it." << std::endl;

        return std::dynamic_pointer_cast<NodeT>((*i).second);
    }

    template<typename NodeT>
    std::shared_ptr<NodeT> nodeByName(const QString& name) const {
        for (auto i : m_nodeV) {
            if (i->name() == name) {
                return std::dynamic_pointer_cast<NodeT>(i);
            }
        }

        throw std::runtime_error(QString("Node with name '%1'' not found in database").arg(name).toStdString().c_str());
    }

    TableSP createValueTable(const QString& n, const QString& c = "");

private:
    void bootstrap();

    void registerNode(AbstractNodeSP n);

    AbstractNodeSPV m_nodeV;
    AbstractNodeSPM m_nodeM;
};

#endif // DATABASE_HXX
