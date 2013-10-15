#include "AbstractNodePayload.hxx"

AbstractNodePayload::AbstractNodePayload()
{
}

AbstractNodePayload::~AbstractNodePayload()
{

}

String AbstractNodePayload::toString() const
{
    return implToString();
}

void AbstractNodePayload::setName(const String &n)
{
    implSetName(n);
}

void AbstractNodePayload::setComment(const String &c)
{
    implSetComment(c);
}

String AbstractNodePayload::name() const
{
    return implName();
}

String AbstractNodePayload::comment() const
{
    return implComment();
}

AbstractNode *AbstractNodePayload::node() const
{
    return implNode();
}

String AbstractNodePayload::implToString() const
{
    return name();
}
