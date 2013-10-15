#include "AbstractEdge.hxx"

#include <AbstractNode.hxx>

AbstractEdge::AbstractEdge()
{
}

AbstractEdge::~AbstractEdge()
{

}

AbstractNodeSP AbstractEdge::left() const
{
    return implLeft();
}

AbstractNodeSP AbstractEdge::right() const
{
    return implRight();
}

void AbstractEdge::setLeft(AbstractNodeSP l)
{
    return implSetLeft(l);
}

void AbstractEdge::setRight(AbstractNodeSP r)
{
    return implSetRight(r);
}

void AbstractEdge::set(AbstractNodeSP l, AbstractNodeSP r)
{
    setLeft(l);
    setRight(r);
}

String AbstractEdge::toString() const
{
    return implToString();
}

Id AbstractEdge::id() const
{
    return implId();
}

EdgeTypes AbstractEdge::edgeType() const
{
    return implEdgeType();
}

String AbstractEdge::implToString() const
{
    StringStream s;

    s << "[" << id() << ", " << edgeTypeToString(edgeType()) << "]: ";

    if (left()) {
        s << left()->toString();
    } else {
        s << "<>";
    }

    s << " <==> ";

    if (right()) {
        s << right()->toString();
    } else {
        s << "<>";
    }

    return s.str();
}
