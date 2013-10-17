#include "Fossil.hxx"

String Fossil::singular()
{
    return "Fossil";
}

String Fossil::plural()
{
    return "Fossils";
}

Fossil::Fossil(AbstractNode *n)
    : ValueNodePayload(n)
{
}

Fossil::~Fossil()
{

}
