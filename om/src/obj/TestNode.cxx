#include "TestNode.hxx"

QString TestNode::singular()
{
    return QObject::tr("Test Node");
}

TestNode::TestNode(const QUuid &id)
    : Object(id)
{
    (void) createProperty<int>("an integer", 1000);
    (void) createProperty<double>("a double", 3.14);
    (void) createProperty<QString>("a string", "hello, world!");
}

TestNode::~TestNode()
{

}
