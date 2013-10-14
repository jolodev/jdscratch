#ifndef ABSTRACTPROPERTY_HXX
#define ABSTRACTPROPERTY_HXX

#include <obj/AbstractPropertyFwd.hxx>

#include <obj/PropertyRole.hxx>

class AbstractProperty
{
public:
    explicit AbstractProperty();
    virtual ~AbstractProperty();

    void setName(const QString& n);

    QString name() const;
    QString valueToString() const;
    QString toString() const;

    void addRole(PropertyRole r);
    bool hasRole(PropertyRole r) const;
    const std::vector<PropertyRole> roles() const;

    void setIsMandatory(bool b);
    void setUseValueAsStorageDefault(bool v);

    bool isMandatory() const;
    bool useValueAsStorageDefault() const;

    QString sqlTypeName() const;

protected:
    virtual QString implSqlTypeName() const = 0;
    virtual QString implName() const = 0;
    virtual QString implValueToString() const = 0;
    virtual QString implToString() const = 0;

    virtual void implSetIsMandatory(bool m) = 0;
    virtual void implSetUseValueAsStorageDefault(bool u) = 0;

    virtual bool implIsMandatory() const = 0;
    virtual bool implUseValueAsStorageDefault() const = 0;

    virtual void implAddRole(PropertyRole r) = 0;
    virtual bool implHasRole(PropertyRole r) const = 0;
    virtual const std::vector<PropertyRole> implRoles() const = 0;
};

#endif // ABSTRACTPROPERTY_HXX
