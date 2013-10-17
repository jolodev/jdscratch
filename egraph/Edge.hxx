#ifndef EDGE_HXX
#define EDGE_HXX

#include <AbstractEdge.hxx>

#include <EdgeProperty.hxx>
#include <EdgeRoles.hxx>

#include <VertexFwd.hxx>
#include <GraphFwd.hxx>
#include <EdgeFwd.hxx>

class Edge : public AbstractEdge
{
public:
    static String idPropertyName();
    static String leftVertrexIdPropertyName();
    static String rightVertexIdPropertyName();
    static String directionPropertyName();
    static String rolePropertyName();

    explicit Edge(GraphP g = nullptr, const EdgeDirections d = EdgeDirections::In,
                  VertexSP left = VertexSP(), VertexSP right = VertexSP(),
                  const EdgeRoles r = EdgeRoles::Unspecified);
    virtual ~Edge();

    AbstractEdgePropertySPV properties() const;

    template<typename ValueT>
    std::shared_ptr<EdgeProperty<ValueT> > property(const String& name) const {
        auto i = m_properties.find(name);

        assert(m_properties.end() != i);

        return std::dynamic_pointer_cast<EdgeProperty<ValueT> >((*i).second);
    }

    template<typename ValueT>
    std::shared_ptr<EdgeProperty<ValueT> > createProperty(const String& name, const ValueT& v) {
        auto p = std::make_shared<EdgeProperty<ValueT> >(EdgeProperty<ValueT>(name, v));
        registerProperty(p);
        return p;
    }

protected:
    void registerProperty(AbstractEdgePropertySP p) {
        m_properties[p->name()] = p;
    }

    GraphP implGraph() const override;

    EdgeDirections implDirection() const override;
    EdgeRoles implRole() const override;

    Id implId() const;
    Id implLeftId() const override;
    Id implRightId() const override;

    void implSetDirection(EdgeDirections d) override;
    void implSetLeftId(const Id& id) override;
    void implSetRightId(const Id& id) override;

    virtual void implSetLeftVertex(VertexSP l) override;
    virtual void implSetRightVertex(VertexSP r) override;

private:
    GraphP m_g { nullptr };

    AbstractEdgePropertySPM m_properties;
};

#endif // EDGE_HXX
