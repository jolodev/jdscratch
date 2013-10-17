#include "ValueNodePayload.hxx"

String ValueNodePayload::singular()
{
    return "Value Node";
}

ValueNodePayload::ValueNodePayload(AbstractNode *n)
    : NodePayload(n)
{
}

ValueNodePayload::~ValueNodePayload()
{

}
