#include "OMTools.hxx"

QUuid OMTools::invalidId()
{
    return QUuid();
}

bool OMTools::isValid(const QUuid &id)
{
    return (!id.isNull());
}

QUuid OMTools::createId()
{
    return QUuid::createUuid();
}
