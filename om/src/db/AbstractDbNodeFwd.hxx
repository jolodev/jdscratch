#ifndef ABSTRACTDBNODEFWD_HXX
#define ABSTRACTDBNODEFWD_HXX

#include <core/Types.hxx>

class AbstractDbNode;
typedef AbstractDbNode* AbstractDbNodeRP;
typedef std::shared_ptr<AbstractDbNode> AbstractDbNodeSP;
typedef std::vector<AbstractDbNodeSP> AbstractDbNodeSPV;
typedef std::map<QString, AbstractDbNodeSP> AbstractDbNodeSPM;

#endif // ABSTRACTDBNODEFWD_HXX
