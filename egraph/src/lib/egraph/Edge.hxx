#ifndef EDGE_HXX
#define EDGE_HXX

#include "AbstractEdge.hxx"

#include "EdgeProperty.hxx"

#include "VertexFwd.hxx"
#include "GraphFwd.hxx"
#include "EdgeFwd.hxx"

namespace EGraph {
class Edge : public AbstractEdge
{
public:
    static String idPropertyName();
    static String leftVertrexIdPropertyName();
    static String rightVertexIdPropertyName();
    static String directionPropertyName();
    static String rolePropertyName();

    explicit Edge(GraphP g, VertexSP left, VertexSP right, const EdgeDirections d, const String r = "");
    virtual ~Edge();

    AbstractEdgePropertySPV properties() const;

    template<typename ValueT>
    boost::shared_ptr<EdgeProperty<ValueT> > property(const String& name) const {
        auto i = m_properties.find(name);

        assert(m_properties.end() != i);

        return boost::dynamic_pointer_cast<EdgeProperty<ValueT> >((*i).second);
    }

    template<typename ValueT>
    boost::shared_ptr<EdgeProperty<ValueT> > createProperty(const String& name, const ValueT& v) {
        auto p = boost::make_shared<EdgeProperty<ValueT> >(EdgeProperty<ValueT>(name, v));
        registerProperty(p);
        return p;
    }

protected:
    // a default ctor is required for boost::serialization
    Edge();

    void registerProperty(AbstractEdgePropertySP p) {
        m_properties[p->name()] = p;
    }

    GraphP implGraph() const override;
    VertexSP implLeftVertex() const override;
    VertexSP implRightVertex() const override;

    EdgeDirections implDirection() const override;
    String implRole() const override;

    Id implId() const;
    Id implLeftVertexId() const override;
    Id implRightVertexId() const override;

    void implSetDirection(EdgeDirections d) override;
    void implSetLeftVertexId(const Id& id) override;
    void implSetRightVertexId(const Id& id) override;

    virtual void implSetLeftVertex(VertexSP l) override;
    virtual void implSetRightVertex(VertexSP r) override;

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& a, const unsigned int v)
    {
        (void) v;

        a & BOOST_SERIALIZATION_BASE_OBJECT_NVP(AbstractEdge);
        a & BOOST_SERIALIZATION_NVP(m_g);
        a & BOOST_SERIALIZATION_NVP(m_properties);
    }

    GraphP m_g { nullptr };

    AbstractEdgePropertySPM m_properties;
};
}

BOOST_CLASS_EXPORT_KEY(EGraph::Edge)

BOOST_CLASS_VERSION(EGraph::Edge, 1)
#endif // EDGE_HXX
