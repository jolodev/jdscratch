#include "Global.hxx"

#include <boost/algorithm/string/join.hpp>

String join(const StringVector &v, const String &sep)
{
    return boost::algorithm::join(v, sep);
}
