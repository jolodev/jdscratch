#include "AbstractRequest.hxx"

using namespace EGraph;

AbstractRequest::AbstractRequest()
{
}

AbstractRequest::~AbstractRequest()
{

}

String AbstractRequest::data() const
{
    return implData();
}
