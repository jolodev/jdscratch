#ifndef ABSTRACTVERTEX_HXX
#define ABSTRACTVERTEX_HXX

#include <Global.hxx>

#include <GraphFwd.hxx>

#include <VertexFwd.hxx>
#include <VertexProperty.hxx>

class Vertex
{
public:
    static String idPropertyName();
    static String labelPropertyName();
    static String typePropertyName();

    explicit Vertex(GraphP g = nullptr, const String& lbl = "", const String& typeName = "");
    virtual ~Vertex();

    GraphP graph() const;

    StringVector propertyNames() const;
    AbstractVertexPropertySPV properties() const;

    template<typename ValueT>
    AbstractVertexPropertySP createProperty(const String& name, const ValueT& value) {
        auto p = std::make_shared<VertexProperty<ValueT> >(VertexProperty<ValueT>(name, value));
        registerProperty(p);
        return p;
    }

    template<typename ValueT>
    std::shared_ptr<VertexProperty<ValueT> > property(const String& name) const {
        auto i = m_properties.find(name);

        assert(m_properties.end() != i);

        return (std::dynamic_pointer_cast<VertexProperty<ValueT> >((*i).second));
    }

protected:
    virtual void registerProperty(AbstractVertexPropertySP p);

private:
    GraphP m_g { nullptr };
    AbstractVertexPropertySPM m_properties;
};

#endif // ABSTRACTVERTEX_HXX
