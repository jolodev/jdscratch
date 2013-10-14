#ifndef PROPERTY_HXX
#define PROPERTY_HXX

#include <obj/AbstractProperty.hxx>

#include <sstream>

template<typename ValueT>
class Property: public AbstractProperty {
public:
    using ValueType = ValueT;

    explicit Property(const QString& name, const ValueType& val, bool isMandatory=false, bool useValueAsStorageDefault=false)
        : AbstractProperty(), m_isMandatory(isMandatory), m_name(name), m_value(val), m_useValueAsStorageDefault(useValueAsStorageDefault) {}

    virtual ~Property() {}

    void set(const ValueType& t) { m_value = t; }
    ValueType get() const { return m_value; }

protected:
    void implSetIsMandatory(bool m) override {
        m_isMandatory = m;
    }

    void implSetUseValueAsStorageDefault(bool u) override {
        m_useValueAsStorageDefault = u;
    }

    bool implIsMandatory() const override {
        return m_isMandatory;
    }

    bool implUseValueAsStorageDefault() const override {
        return m_useValueAsStorageDefault;
    }

    QString implName() const override { return m_name; }
    QString implToString() const override {
        return QString("%1: %2").arg(name()).arg(valueToString());
    }

    QString implValueToString() const override {
        std::stringstream s;
        s << get();
        return QString::fromStdString(s.str());
    }

    virtual QString implSqlTypeName() const {
        if (typeid(ValueType) == typeid(QString)) { return "TEXT"; }
        else if (typeid(ValueType) == typeid(QUuid)) { return "UUID"; }
        else if (typeid(ValueType) == typeid(int)) { return "INTEGER"; }
        else if (typeid(ValueType) == typeid(double)) { return "NUMERIC"; }
        else if (typeid(ValueType) == typeid(qulonglong)) { return "BIGINT"; }
        else if (typeid(ValueType) == typeid(QUuidV)) { return "UUID[]"; }
        else if (typeid(ValueType) == typeid(QDateTime)) { return "TIMESTAMP"; }
        else { assert(false); }
    }

    virtual void implAddRole(PropertyRole r) {
        m_roles.push_back(r);
    }

    virtual bool implHasRole(PropertyRole r) const {
        for (auto i : roles()) {
            if (r == i) {
                return true;
            }
        }

        return false;
    }

    virtual const std::vector<PropertyRole> implRoles() const {
        return m_roles;
    }

private:
    bool m_isMandatory { false };
    QString m_name;
    ValueType m_value;
    bool m_useValueAsStorageDefault { false };
    bool m_isPrimaryKey { false };
    std::vector<PropertyRole> m_roles;

};

#endif // PROPERTY_HXX
