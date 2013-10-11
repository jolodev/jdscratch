#include "Object.hxx"

QString Object::idPropertyName()
{
    return "ID";
}

Object::Object(const QUuid &id)
    : AbstractObject()
{
    (void) createProperty<QUuid>(Object::idPropertyName(), id);
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
    return std::dynamic_pointer_cast<Property<QUuid> >(property(Object::idPropertyName()))->get();
}

void Object::implRegisterProperty(AbstractPropertySP p)
{
    m_propertyV.push_back(p);
    m_propertyM[p->name()] = p;
}

AbstractPropertySP Object::implProperty(const QString &name) const
{
    auto i = m_propertyM.find(name);

    assert(m_propertyM.end() != i);

    return (*i).second;
}

const AbstractPropertySPV Object::implProperties() const
{
    return m_propertyV;
}
