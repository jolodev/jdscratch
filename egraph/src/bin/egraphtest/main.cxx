#include <egraph/Graph.hxx>
#include <egraph/Storage.hxx>
#include <egraphsrv/Formater.hxx>
#include <egraphsrv/HtmlFormat.hxx>

#include <Config.hxx>

using namespace EGraph;
using namespace Config;

int main()
{
    auto g = boost::make_shared<Graph>(Graph("graph.xml"));

    g->registerEdgeRole(RoleTypes::Contains);
    g->registerEdgeRole(RoleTypes::IsPartOf);
    g->registerEdgeRole(RoleTypes::IsSubType);
    g->registerEdgeRole(RoleTypes::IsSuperType);

    auto model = g->createVertex(VertexTypes::Model, "model");

    auto genericFossil = g->createVertex(VertexTypes::FossilType, "Generic Fossil");
    auto bodyFossil = g->createVertex(VertexTypes::FossilType, "Body Fossil");
    auto boneFossil = g->createVertex(VertexTypes::FossilType, "Bone Fossil");

    g->createEdge(genericFossil, model, RoleTypes::IsPartOf);
    g->createEdge(model, genericFossil, RoleTypes::Contains);

    g->createEdge(bodyFossil, genericFossil, RoleTypes::IsSubType);
    g->createEdge(genericFossil, bodyFossil, RoleTypes::IsSuperType);

    g->createEdge(boneFossil, bodyFossil, RoleTypes::IsSubType);
    g->createEdge(bodyFossil, boneFossil, RoleTypes::IsSuperType);
/*
    g->debug();

    Graph::debug(g->verticesWithType(VertexTypes::Model), "Model");
    Graph::debug(g->edges(model, EdgeDirections::Out), "Outgoing Edges from " + model->toString());
    Graph::debug(g->edges(genericFossil, EdgeDirections::In), "Incoming Edges to " + genericFossil->toString());

    Storage::save<boost::archive::xml_oarchive>(g);

    auto g2 = Storage::load<boost::archive::xml_iarchive>(g->fileName());
    auto boneFossil2 = g2->vertex(boneFossil->id());
    assert(boneFossil2);
    assert(boneFossil2->id() == boneFossil->id());
    g2->removeVertex(boneFossil2);
    g2->debug();
*/
    //std::cout << srv->present(model) << std::endl;

    auto formater = Formater<HtmlFormat>();

    std::cout << std::endl << formater.present(model,
                                               g->edges(model, EdgeDirections::In),
                                               g->edges(model, EdgeDirections::Out)) << std::endl;

    return EXIT_SUCCESS;
}

