#ifndef VERTEXTYPES_HXX
#define VERTEXTYPES_HXX

#include <Global.hxx>

namespace Config {

namespace VertexTypes {
const EGraph::String Model { "Model" };
const EGraph::String FossilType { "Fossil Type" };
}

namespace RoleTypes {
const EGraph::String IsPartOf { "Is Part Of" };
const EGraph::String Contains { "Contains" };
const EGraph::String IsSubType { "Is Sub Type" };
const EGraph::String IsSuperType { "Is Super Type" };
}
}

#endif // VERTEXTYPES_HXX
