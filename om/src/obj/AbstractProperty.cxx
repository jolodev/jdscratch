#include "AbstractProperty.hxx"

AbstractProperty::AbstractProperty()
{
}

AbstractProperty::~AbstractProperty()
{

}

QString AbstractProperty::name() const
{
    return implName();
}

QString AbstractProperty::valueToString() const
{
    return implValueToString();
}

QString AbstractProperty::toString() const
{
    return implToString();
}

void AbstractProperty::addRole(PropertyRole r)
{
    implAddRole(r);
}

bool AbstractProperty::hasRole(PropertyRole r) const
{
    return implHasRole(r);
}

const std::vector<PropertyRole> AbstractProperty::roles() const
{
    return implRoles();
}

void AbstractProperty::setIsMandatory(bool b)
{
    implSetIsMandatory(b);
}

void AbstractProperty::setUseValueAsStorageDefault(bool v)
{
    implSetUseValueAsStorageDefault(v);
}

bool AbstractProperty::isMandatory() const
{
    return implIsMandatory();
}

bool AbstractProperty::useValueAsStorageDefault() const
{
    return implUseValueAsStorageDefault();
}

QString AbstractProperty::sqlTypeName() const
{
    return implSqlTypeName();
}
