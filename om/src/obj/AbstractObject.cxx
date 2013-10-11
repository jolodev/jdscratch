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
