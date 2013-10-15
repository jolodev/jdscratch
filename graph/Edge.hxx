#ifndef EDGE_HXX
#define EDGE_HXX

#include <AbstractEdge.hxx>

#include <Tools.hxx>

class Edge : public AbstractEdge
{
public:
    explicit Edge(EdgeTypes t, AbstractNodeSP l, AbstractNodeSP r);
    virtual ~Edge();

protected:
    EdgeTypes implEdgeType() const override;
    Id implId() const override;

    virtual AbstractNodeSP implLeft() const override;
    virtual AbstractNodeSP implRight() const override;

    virtual void implSetLeft(AbstractNodeSP l) override;
    virtual void implSetRight(AbstractNodeSP r) override;

private:
    EdgeTypes m_type { EdgeTypes::Unknown };
    Id m_id { invalidId() };
    AbstractNodeSP m_left;
    AbstractNodeSP m_right;
};

#endif // EDGE_HXX
