#include "TestNode.hxx"

QString TestNode::singular()
{
    return QObject::tr("Test Node");
}

QString TestNode::plural()
{
    return QObject::tr("Test Nodes");
}

TestNode::TestNode(const QUuid &id)
    : Object(id)
{
    (void) createProperty<int>("an integer", 1000, false, true);
    (void) createProperty<double>("a double", 3.14, false, true);
    (void) createProperty<QString>("a string", "hello, world!", true, true);
    (void) createProperty<QUuidV>("a vector of ids", QUuidV(), true, false);
}

TestNode::~TestNode()
{

}
