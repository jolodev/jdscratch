#include <Graph.hxx>

#include <Node.hxx>
#include <Fossil.hxx>
#include <FossilType.hxx>

int main()
{
    auto g = std::make_shared<Graph>(Graph());

    auto genericFossil = g->createNode<FossilType>();
    genericFossil->data()->setName("Generic Fossil");

    auto shell = g->createNode<FossilType>();
    shell->data()->setName("Shell");

    auto fossil = g->createNode<Fossil>();
    fossil->data()->setName("A shell fossil");

    (void) g->createEdge(EdgeTypes::ParentChild, genericFossil, shell);
    (void) g->createEdge(EdgeTypes::Reference, fossil, shell);

    g->printOn(std::cout);
    g->printTypedNodes<FossilType>(std::cout);
    g->printEdgesWithLeftNode(genericFossil, std::cout);
    g->printEdgesWithRightNode(shell, std::cout);

    std::cout << std::endl << std::endl << "exiting..." << std::endl << std::endl;

    return EXIT_SUCCESS;
}

