#ifndef ABSTRACTEDGE_HXX
#define ABSTRACTEDGE_HXX

#include <Global.hxx>

#include <GraphFwd.hxx>
#include <VertexFwd.hxx>

#include <EdgeDirections.hxx>
#include <EdgeRoles.hxx>

class AbstractEdge
{
public:
    explicit AbstractEdge();
    virtual ~AbstractEdge();

    GraphP graph() const;

    EdgeDirections direction() const;
    EdgeRoles role() const;

    Id id() const;
    Id leftId() const;
    Id rightId() const;

    void setDirection(EdgeDirections d);
    void setLeftId(const Id& id);
    void setRightId(const Id& id);

    void setLeftVertex(VertexSP v);
    void setRightVertex(VertexSP v);

    void setVertices(VertexSP l, VertexSP r);

    String toString() const;

protected:
    virtual String implToString() const;

    virtual GraphP implGraph() const = 0;
    virtual EdgeDirections implDirection() const = 0;
    virtual EdgeRoles implRole() const = 0;

    virtual Id implId() const = 0;
    virtual Id implLeftId() const = 0;
    virtual Id implRightId() const = 0;

    virtual void implSetLeftVertex(VertexSP l) = 0;
    virtual void implSetRightVertex(VertexSP r) = 0;
    virtual void implSetDirection(EdgeDirections d) = 0;
    virtual void implSetLeftId(const Id& id) = 0;
    virtual void implSetRightId(const Id& id) = 0;
};

#endif // ABSTRACTEDGE_HXX
