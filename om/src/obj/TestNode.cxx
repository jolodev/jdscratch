#include "TestNode.hxx"

QString TestNode::singular()
{
    return QObject::tr("Test Node");
}

TestNode::TestNode(const QUuid &id)
    : Object(id)
{
}

TestNode::~TestNode()
{

}
