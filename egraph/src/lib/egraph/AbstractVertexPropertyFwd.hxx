#ifndef ABSTRACTVERTEXPROPERTYFWD_HXX
#define ABSTRACTVERTEXPROPERTYFWD_HXX

#include "Global.hxx"

namespace EGraph {
class AbstractVertexProperty;
typedef boost::shared_ptr<AbstractVertexProperty> AbstractVertexPropertySP;
typedef std::vector<AbstractVertexPropertySP> AbstractVertexPropertySPV;
typedef std::map<String, AbstractVertexPropertySP> AbstractVertexPropertySPM;
}

#endif // ABSTRACTVERTEXPROPERTYFWD_HXX
