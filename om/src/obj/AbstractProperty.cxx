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
