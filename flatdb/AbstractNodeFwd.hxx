#ifndef ABSTRACTNODEFWD_HXX
#define ABSTRACTNODEFWD_HXX

#include <Types.hxx>

class AbstractNode;
typedef AbstractNode* AbstractNodeP;
typedef std::shared_ptr<AbstractNode> AbstractNodeSP;
typedef std::map<Id, AbstractNodeSP> AbstractNodeSPM;
typedef std::vector<AbstractNodeSP> AbstractNodeSPV;

#endif // ABSTRACTNODEFWD_HXX
