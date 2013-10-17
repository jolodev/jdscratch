#include "FossilType.hxx"

String FossilType::singular()
{
    return "Fossil Type";
}

String FossilType::plural()
{
    return "Fossil Types";
}

FossilType::FossilType(AbstractNode *n)
    : ValueNodePayload(n)
{
}

FossilType::~FossilType()
{

}
