#ifndef NODEFWD_HXX
#define NODEFWD_HXX

#include <Types.hxx>

class Node;
typedef Node* NodeP;
typedef std::shared_ptr<Node> NodeSP;
typedef std::vector<NodeSP> NodeSPV;

#endif // NODEFWD_HXX
