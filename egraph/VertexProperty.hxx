#ifndef VERTEXPROPERTY_HXX
#define VERTEXPROPERTY_HXX

#include <AbstractVertexProperty.hxx>

namespace EGraph {
template<typename ValueT>
class VertexProperty: public AbstractVertexProperty {
public:
    explicit VertexProperty(const String& n = "", const ValueT& v = ValueT())
        : AbstractVertexProperty(), m_name(n), m_value(v) {}
    virtual ~VertexProperty() {}

    void setValue(const ValueT& v) { m_value = v; }

    ValueT value() const { return m_value; }

    String valueToString() const { StringStream s; s << value(); return s.str(); }

protected:
    String implName() const override { return m_name; }
    String implToString() const override {
        StringStream s;
        s << name() << ": " << valueToString();
        return s.str();
    }

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& a, const unsigned int v)
    {
        (void) v;

        a & BOOST_SERIALIZATION_BASE_OBJECT_NVP(AbstractVertexProperty);
        a & BOOST_SERIALIZATION_NVP(m_name);
        a & BOOST_SERIALIZATION_NVP(m_value);
    }

    String m_name { "" };
    ValueT m_value;
};
}

BOOST_CLASS_EXPORT_KEY(EGraph::VertexProperty<EGraph::String>)
BOOST_CLASS_EXPORT_KEY(EGraph::VertexProperty<EGraph::Id>)

BOOST_CLASS_VERSION(EGraph::VertexProperty<EGraph::String>, 1)
BOOST_CLASS_VERSION(EGraph::VertexProperty<EGraph::Id>, 1)


#endif // VERTEXPROPERTY_HXX
