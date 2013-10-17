#include <Graph.hxx>

#include <Vertex.hxx>
#include <Edge.hxx>
#include <VertexTypes.hxx>
#include <Storage.hxx>

using namespace EGraph;

int main()
{
    auto g = boost::make_shared<Graph>(Graph("graph.xml"));

    auto model = g->createVertex(VertexTypes::Model, "model");

    auto genericFossil = g->createVertex(VertexTypes::FossilType, "Generic Fossil");
    auto bodyFossil = g->createVertex(VertexTypes::FossilType, "Body Fossil");
    auto boneFossil = g->createVertex(VertexTypes::FossilType, "Bone Fossil");

    g->createEdge(genericFossil, model, EdgeRoles::IsPartOf);
    g->createEdge(model, genericFossil, EdgeRoles::Contains);

    g->createEdge(bodyFossil, genericFossil, EdgeRoles::IsSubType);
    g->createEdge(genericFossil, bodyFossil, EdgeRoles::IsSuperType);

    g->createEdge(boneFossil, bodyFossil, EdgeRoles::IsSubType);
    g->createEdge(bodyFossil, boneFossil, EdgeRoles::IsSuperType);

    g->debug();

    Graph::debug(g->verticesWithType(VertexTypes::Model), "Model");
    Graph::debug(g->edges(model, EdgeDirections::Out), "Outgoing Edges from " + model->toString());
    Graph::debug(g->edges(genericFossil, EdgeDirections::In), "Incoming Edges to " + genericFossil->toString());

    Storage::save<boost::archive::xml_oarchive>(g);

    auto g2 = Storage::load<boost::archive::xml_iarchive>("graph.xml");
    g2->debug();

    return EXIT_SUCCESS;
}

