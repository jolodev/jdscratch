#include <Graph.hxx>

#include <Node.hxx>
#include <NodePayload.hxx>
#include <FossilType.hxx>

int main()
{
    auto g = std::make_shared<Graph>(Graph());

    auto genericFossil = g->createNode<FossilType>();
    genericFossil->data()->setName("Generic Fossil");

    auto shell = g->createNode<FossilType>();
    shell->data()->setName("Shell");

    auto v1 = g->createNode<ValueNodePayload>();
    v1->data()->setName("V1");

    (void) g->createEdge(EdgeTypes::ParentChild, genericFossil, shell);
    (void) g->createEdge(EdgeTypes::Reference, v1, shell);

    g->printOn(std::cout);
    g->printTypedNodes<FossilType>(std::cout);

    std::cout << std::endl << "exiting..." << std::endl << std::endl;
    return EXIT_SUCCESS;
}

