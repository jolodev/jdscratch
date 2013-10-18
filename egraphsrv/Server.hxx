#ifndef SERVER_HXX
#define SERVER_HXX

#include <AbstractServer.hxx>

#include <AbstractFormatDialect.hxx>

namespace EGraph {
template<typename FormatDialectT>
class Server: public AbstractServer {
public:
    explicit Server(GraphSP g)
        : AbstractServer(), m_g(g) {}
    virtual ~Server() {}

protected:
    void implSetGraph(GraphSP g) { m_g = g; }
    GraphSP implGraph() const { return m_g; }
    AbstractFormatDialect* dialect() { return &m_d; }

private:
    GraphSP m_g;
    FormatDialectT m_d { FormatDialectT() };
};
}

#endif // SERVER_HXX
