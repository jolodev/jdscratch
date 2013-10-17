#include "Global.hxx"

#include <boost/algorithm/string/join.hpp>

using namespace EGraph;

String join(const StringVector &v, const String &sep)
{
    return boost::algorithm::join(v, sep);
}
