#include "AbstractObject.hxx"

AbstractObject::AbstractObject()
{
}

AbstractObject::~AbstractObject()
{

}

QString AbstractObject::toString() const
{
    return implToString();
}

QUuid AbstractObject::id() const
{
    return implId();
}

void AbstractObject::registerProperty(AbstractPropertySP p)
{
    implRegisterProperty(p);
}

AbstractPropertySP AbstractObject::property(const QString &name) const
{
    return implProperty(name);
}

const AbstractPropertySPV AbstractObject::properties() const
{
    return implProperties();
}
