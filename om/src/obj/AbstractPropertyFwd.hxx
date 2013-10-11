#ifndef ABSTRACTPROPERTYFWD_HXX
#define ABSTRACTPROPERTYFWD_HXX

#include <obj/AbstractObjectFwd.hxx>

class AbstractProperty;
typedef AbstractProperty* AbstractPropertyRP;
typedef std::shared_ptr<AbstractProperty> AbstractPropertySP;
typedef std::vector<AbstractPropertySP> AbstractPropertySPV;
typedef std::map<QString, AbstractPropertySP> AbstractPropertySPM;

#endif // ABSTRACTPROPERTYFWD_HXX
