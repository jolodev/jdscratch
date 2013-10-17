#ifndef VERTEXPROPERTY_HXX
#define VERTEXPROPERTY_HXX

#include <Global.hxx>

class AbstractVertexProperty {
public:
    String name() const { return implName(); }
    String toString() const { return implToString(); }

protected:
    virtual String implName() const = 0;
    virtual String implToString() const = 0;
};

typedef std::shared_ptr<AbstractVertexProperty> AbstractVertexPropertySP;
typedef std::vector<AbstractVertexPropertySP> AbstractVertexPropertySPV;
typedef std::map<String, AbstractVertexPropertySP> AbstractVertexPropertySPM;

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
    String m_name { "" };
    ValueT m_value;
};

#endif // VERTEXPROPERTY_HXX
