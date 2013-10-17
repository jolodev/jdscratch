TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
QMAKE_CXX = clang++
QMAKE_CXXFLAGS = -Wall -Werror

SOURCES += \
    Global.cxx \
    Graph.cxx \
    AbstractEdge.cxx \
    Vertex.cxx \
    Edge.cxx \
    main.cxx \
    EdgeDirections.cxx \
    EdgeRoles.cxx

HEADERS += \
    Global.hxx \
    Graph.hxx \
    GraphFwd.hxx \
    AbstractEdge.hxx \
    Edge.hxx \
    VertexProperty.hxx \
    EdgeFwd.hxx \
    EdgeDirections.hxx \
    Vertex.hxx \
    VertexFwd.hxx \
    EdgeRoles.hxx \
    EdgeProperty.hxx \
    VertexTypes.hxx

