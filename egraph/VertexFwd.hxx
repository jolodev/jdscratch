#ifndef VERTEXFWD_HXX
#define VERTEXFWD_HXX

#include <Global.hxx>

class Vertex;
typedef Vertex* VertexP;
typedef boost::shared_ptr<Vertex> VertexSP;
typedef std::vector<VertexSP> VertexSPV;
typedef std::map<Id, VertexSP> VertexSPM;

#endif // VERTEXFWD_HXX
