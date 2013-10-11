#ifndef PROPERTY_HXX
#define PROPERTY_HXX

#include <obj/AbstractProperty.hxx>

#include <sstream>

template<typename ValueT>
class Property: public AbstractProperty {
public:
    using ValueType = ValueT;

    explicit Property(const QString& name, const ValueType& val)
        : AbstractProperty(), m_name(name), m_value(val) {}

    virtual ~Property() {}

    void set(const ValueType& t) { m_value = t; }
    ValueType get() const { return m_value; }

protected:
    QString implName() const override { return m_name; }
    QString implToString() const override {
        return QString("%1: %2").arg(name()).arg(valueToString());
    }

    QString implValueToString() const override {
        std::stringstream s;
        s << get();
        return QString::fromStdString(s.str());
    }

private:
    QString m_name;
    ValueType m_value;
};

#endif // PROPERTY_HXX
