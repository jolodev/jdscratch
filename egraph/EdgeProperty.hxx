#ifndef EDGEPROPERTY_HXX
#define EDGEPROPERTY_HXX

#include <Global.hxx>

#include <EdgeDirections.hxx>

class AbstractEdgeProperty {
public:
    String name() const { return implName(); }
    String toString() const { return implToString(); }

protected:
    virtual String implName() const = 0;
    virtual String implToString() const = 0;
};

typedef std::shared_ptr<AbstractEdgeProperty> AbstractEdgePropertySP;
typedef std::vector<AbstractEdgePropertySP> AbstractEdgePropertySPV;
typedef std::map<String, AbstractEdgePropertySP> AbstractEdgePropertySPM;

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
    String m_name { "" };
    ValueT m_value;
};

#endif // EdgePROPERTY_HXX
