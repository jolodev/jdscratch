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
    Id leftVertexId() const;
    Id rightVertexId() const;

    VertexSP leftVertex() const;
    VertexSP rightVertex() const;

    void setDirection(EdgeDirections d);
    void setLeftId(const Id& id);
    void setRightId(const Id& id);

    void setLeftVertex(VertexSP v);
    void setRightVertex(VertexSP v);

    void setVertices(VertexSP l, VertexSP r);

    String toString() const;

protected:
    virtual String connectionInfoToString(const EdgeDirections d, const EdgeRoles r) const;

    virtual String implToString() const;

    virtual GraphP implGraph() const = 0;
    virtual VertexSP implLeftVertex() const = 0;
    virtual VertexSP implRightVertex() const = 0;

    virtual EdgeDirections implDirection() const = 0;
    virtual EdgeRoles implRole() const = 0;

    virtual Id implId() const = 0;
    virtual Id implLeftVertexId() const = 0;
    virtual Id implRightVertexId() const = 0;

    virtual void implSetLeftVertex(VertexSP l) = 0;
    virtual void implSetRightVertex(VertexSP r) = 0;
    virtual void implSetDirection(EdgeDirections d) = 0;
    virtual void implSetLeftVertexId(const Id& id) = 0;
    virtual void implSetRightVertexId(const Id& id) = 0;

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& a, const unsigned int v)
    {
        (void) a;
        (void) v;
    }
};

BOOST_SERIALIZATION_ASSUME_ABSTRACT(AbstractEdge)

BOOST_CLASS_VERSION(AbstractEdge, 1)

#endif // ABSTRACTEDGE_HXX
