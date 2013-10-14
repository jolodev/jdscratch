#include "Object.hxx"

QString Object::idPropertyName()
{
    return "ID";
}

QString Object::versionPropertyName()
{
    return "Object Version";
}

QString Object::creationTimestampName()
{
    return "Created";
}

QString Object::lastModificationTimestampName()
{
    return "Modified";
}

Object::Object(const QUuid &id)
    : AbstractObject()
{
    auto idP = createProperty<QUuid>(Object::idPropertyName(), id, true, false);
    idP->addRole(PropertyRole::PrimaryKey);

    auto version = createProperty<qulonglong>(Object::versionPropertyName(), 0, true, true);
    version->addRole(PropertyRole::Version);

    auto creat = createProperty<QDateTime>(Object::creationTimestampName(), QDateTime::currentDateTime(), true, true);
    creat->addRole(PropertyRole::Creation);

    auto mod = createProperty<QDateTime>(Object::lastModificationTimestampName(), QDateTime::currentDateTime(), true, true);
    mod->addRole(PropertyRole::LastModification);
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
