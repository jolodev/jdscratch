#ifndef EDGEPROPERTY_HXX
#define EDGEPROPERTY_HXX

#include <AbstractEdgeProperty.hxx>

#include <EdgeProperty.hxx>
#include <EdgeRoles.hxx>

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

BOOST_CLASS_EXPORT_KEY(EdgeProperty<String>)
BOOST_CLASS_EXPORT_KEY(EdgeProperty<Id>)
BOOST_CLASS_EXPORT_KEY(EdgeProperty<EdgeDirections>)
BOOST_CLASS_EXPORT_KEY(EdgeProperty<EdgeRoles>)

BOOST_CLASS_VERSION(EdgeProperty<String>, 1)
BOOST_CLASS_VERSION(EdgeProperty<Id>, 1)
BOOST_CLASS_VERSION(EdgeProperty<EdgeDirections>, 1)
BOOST_CLASS_VERSION(EdgeProperty<EdgeRoles>, 1)

#endif // EdgePROPERTY_HXX
