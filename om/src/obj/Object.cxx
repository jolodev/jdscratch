#include "Object.hxx"

Object::Object(const QUuid &id)
    : AbstractObject(), m_id(id)
{
}

Object::~Object()
{

}

QString Object::implToString() const
{
    return id().toString();
}

QUuid Object::implId() const
{
    return m_id;
}
