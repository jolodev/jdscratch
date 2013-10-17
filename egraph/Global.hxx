#ifndef GLOBAL_HXX
#define GLOBAL_HXX

#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <memory>
#include <iostream>

#include <cassert>
#include <cstdlib>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

typedef std::string String;
typedef std::stringstream StringStream;

typedef boost::uuids::uuid Uuid;

typedef Uuid Id;
typedef std::vector<String> StringVector;

String join(const StringVector& v, const String& sep = ", ");

#endif // GLOBAL_HXX
