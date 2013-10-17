#ifndef EDGEPROPERTY_HXX
#define EDGEPROPERTY_HXX

#include <AbstractEdgeProperty.hxx>

#include <EdgeProperty.hxx>
#include <EdgeRoles.hxx>

namespace EGraph {
template<typename ValueT>
class EdgeProperty: public AbstractEdgeProperty {
public:
    explicit EdgeProperty(const String& n = "", const ValueT& v = ValueT())
        : AbstractEdgeProperty(), m_name(n), m_value(v) {}
    virtual ~EdgeProperty() {}

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

            a & BOOST_SERIALIZATION_BASE_OBJECT_NVP(AbstractEdgeProperty);
            a & BOOST_SERIALIZATION_NVP(m_name);
            a & BOOST_SERIALIZATION_NVP(m_value);
        }

    String m_name { "" };
    ValueT m_value;
};
}

BOOST_CLASS_EXPORT_KEY(EGraph::EdgeProperty<EGraph::String>)
BOOST_CLASS_EXPORT_KEY(EGraph::EdgeProperty<EGraph::Id>)
BOOST_CLASS_EXPORT_KEY(EGraph::EdgeProperty<EGraph::EdgeDirections>)
BOOST_CLASS_EXPORT_KEY(EGraph::EdgeProperty<EGraph::EdgeRoles>)

BOOST_CLASS_VERSION(EGraph::EdgeProperty<EGraph::String>, 1)
BOOST_CLASS_VERSION(EGraph::EdgeProperty<EGraph::Id>, 1)
BOOST_CLASS_VERSION(EGraph::EdgeProperty<EGraph::EdgeDirections>, 1)
BOOST_CLASS_VERSION(EGraph::EdgeProperty<EGraph::EdgeRoles>, 1)

#endif // EdgePROPERTY_HXX
