#include <Graph.hxx>

#include <Vertex.hxx>
#include <Edge.hxx>
#include <VertexTypes.hxx>

int main()
{
    auto g = Graph();

    auto model = g.createVertex(VertexTypes::Model, "model");

    auto genericFossil = g.createVertex(VertexTypes::FossilType, "Generic Fossil");
    auto bodyFossil = g.createVertex(VertexTypes::FossilType, "Body Fossil");
    auto boneFossil = g.createVertex(VertexTypes::FossilType, "Bone Fossil");

    g.createEdge(EdgeDirections::Out, genericFossil, bodyFossil, EdgeRoles::IsSubType);
    g.createEdge(EdgeDirections::In, bodyFossil, genericFossil, EdgeRoles::IsSuperType);
    g.createEdge(EdgeDirections::Out, bodyFossil, boneFossil, EdgeRoles::IsSubType);
    g.createEdge(EdgeDirections::In, bodyFossil, boneFossil, EdgeRoles::IsSuperType);
    g.createEdge(EdgeDirections::Out, model, genericFossil, EdgeRoles::IsPartOf);

    g.debug(std::cout);

    return EXIT_SUCCESS;
}

