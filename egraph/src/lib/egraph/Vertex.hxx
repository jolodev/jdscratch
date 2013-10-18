#ifndef ABSTRACTVERTEX_HXX
#define ABSTRACTVERTEX_HXX

#include "Global.hxx"

#include "GraphFwd.hxx"

#include "VertexFwd.hxx"
#include "VertexProperty.hxx"

namespace EGraph {
class Vertex
{
public:
    static String idPropertyName();
    static String labelPropertyName();
    static String typePropertyName();

    explicit Vertex(GraphP g = nullptr, const String& lbl = "", const String& typeName = "");
    virtual ~Vertex();

    GraphP graph() const;

    String toString() const;

    Id id() const;
    String label() const;
    String type() const;

    StringVector propertyNames() const;
    AbstractVertexPropertySPV properties() const;

    template<typename ValueT>
    AbstractVertexPropertySP createProperty(const String& name, const ValueT& value) {
        auto p = boost::make_shared<VertexProperty<ValueT> >(VertexProperty<ValueT>(name, value));
        registerProperty(p);
        return p;
    }

    template<typename ValueT>
    boost::shared_ptr<VertexProperty<ValueT> > property(const String& name) const {
        auto i = m_properties.find(name);

        assert(m_properties.end() != i);

        return (boost::dynamic_pointer_cast<VertexProperty<ValueT> >((*i).second));
    }

protected:
    virtual void registerProperty(AbstractVertexPropertySP p);

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& a, const unsigned int v)
    {
        (void) v;

        a & BOOST_SERIALIZATION_NVP(m_g);
        a & BOOST_SERIALIZATION_NVP(m_properties);
    }

    GraphP m_g { nullptr };
    AbstractVertexPropertySPM m_properties;
};
}

BOOST_CLASS_EXPORT_KEY(EGraph::Vertex)

BOOST_CLASS_VERSION(EGraph::Vertex, 1)

#endif // ABSTRACTVERTEX_HXX
