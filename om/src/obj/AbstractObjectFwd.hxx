#ifndef ABSTRACTOBJECTFWD_HXX
#define ABSTRACTOBJECTFWD_HXX

#include <core/Types.hxx>

class AbstractObject;
typedef AbstractObject* AbstractObjectRP;
typedef std::shared_ptr<AbstractObject> AbstractObjectSP;
typedef std::vector<AbstractObjectSP> AbstractObjectSPV;

#endif // ABSTRACTOBJECTFWD_HXX
