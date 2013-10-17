#ifndef EDGEFWD_HXX
#define EDGEFWD_HXX

#include <Global.hxx>

class Edge;
typedef Edge* EdgeP;
typedef boost::shared_ptr<Edge> EdgeSP;
typedef std::vector<EdgeSP> EdgeSPV;
typedef std::map<Id, EdgeSP> EdgeSPM;

#endif // EDGEFWD_HXX
