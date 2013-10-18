#include "MainWindow.hxx"

#include <egraph/Graph.hxx>
#include <egraph/Storage.hxx>
#include <egraphsrv/Formater.hxx>
#include <egraphsrv/HtmlFormat.hxx>

#include "GraphBrowser.hxx"

#include "Config.hxx"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_gb = new GraphBrowser(this);
    setCentralWidget(m_gb);

    onRun();
}

MainWindow::~MainWindow()
{
}

void MainWindow::onRun()
{
    using namespace EGraph;
    using namespace Config;

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

    auto formater = Formater<HtmlFormat>();

    m_gb->setHtml(QString::fromStdString(formater.present(model,
                                                          g->edges(model, EdgeDirections::In),
                                                          g->edges(model, EdgeDirections::Out))));
}
