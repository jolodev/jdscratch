#ifndef ABSTRACTEDGEPROPERTYFWD_HXX
#define ABSTRACTEDGEPROPERTYFWD_HXX

#include "Global.hxx"
#include "EdgeDirections.hxx"

namespace EGraph {
class AbstractEdgeProperty;
typedef boost::shared_ptr<AbstractEdgeProperty> AbstractEdgePropertySP;
typedef std::vector<AbstractEdgePropertySP> AbstractEdgePropertySPV;
typedef std::map<String, AbstractEdgePropertySP> AbstractEdgePropertySPM;
}

#endif // ABSTRACTEDGEPROPERTYFWD_HXX
