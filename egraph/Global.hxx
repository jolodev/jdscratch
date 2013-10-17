#ifndef GLOBAL_HXX
#define GLOBAL_HXX

#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <iostream>

#include <cassert>
#include <cstdlib>

#include <boost/smart_ptr.hpp>

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/export.hpp>

#include <boost/uuid/uuid_serialize.hpp>

typedef std::string String;
typedef std::stringstream StringStream;

typedef boost::uuids::uuid Uuid;

typedef Uuid Id;
typedef std::vector<String> StringVector;

String join(const StringVector& v, const String& sep = ", ");

#endif // GLOBAL_HXX
