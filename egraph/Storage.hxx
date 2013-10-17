#ifndef STORAGE_HXX
#define STORAGE_HXX

#include <Global.hxx>

#include <Graph.hxx>
#include <Edge.hxx>
#include <Vertex.hxx>
#include <EdgeProperty.hxx>
#include <VertexProperty.hxx>

#include <fstream>

namespace Storage {

template<typename ArchiveT>
void save(GraphSP g) {
    std::ofstream f(g->fileName());
    ArchiveT oa(f);

    oa << BOOST_SERIALIZATION_NVP(g);
    f.flush();
    f.close();
}

template<typename ArchiveT>
GraphSP load(const String &path)
{
    std::ifstream f(path);
    ArchiveT ia(f);

    auto g = boost::make_shared<Graph>(Graph(path));
    ia >> BOOST_SERIALIZATION_NVP(g);

    return g;
}
}

#endif // STORAGE_HXX
