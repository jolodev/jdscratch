#include "Tools.hxx"

#include <AbstractNode.hxx>

std::ostream &operator<<(std::ostream &strm, const QString &str)
{
    strm << str.toStdString();
    return strm;
}

void debug(std::ostream &strm, AbstractNodeSP n, const QString &indent)
{
    strm << indent << n->toString() << std::endl;

    for (auto c : n->childNodes()) {
        debug(strm, c, indent + "    ");
    }
}
