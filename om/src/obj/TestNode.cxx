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
    (void) createProperty<int>("an integer", 1000);
    (void) createProperty<double>("a double", 3.14);
    (void) createProperty<QString>("a string", "hello, world!");
    (void) createProperty<QUuidV>("a vector of ids", {OMTools::createId(), OMTools::createId()});
}

TestNode::~TestNode()
{

}
