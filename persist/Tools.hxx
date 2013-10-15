#ifndef TOOLS_HXX
#define TOOLS_HXX

#include <Types.hxx>

#include <AbstractNodeFwd.hxx>

std::ostream& operator<<(std::ostream& strm, const QString& str);

void debug(std::ostream& strm, AbstractNodeSP n, const QString& indent = "");

#endif // TOOLS_HXX
