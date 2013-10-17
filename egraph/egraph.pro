TEMPLATE = lib
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
    EdgeDirections.cxx \
    Storage.cxx \
    EdgeProperty.cxx \
    VertexProperty.cxx

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
    EdgeProperty.hxx \
    AbstractVertexProperty.hxx \
    AbstractVertexPropertyFwd.hxx \
    AbstractEdgeProperty.hxx \
    AbstractEdgePropertyFwd.hxx \
    Storage.hxx

unix:!macx: LIBS += -lboost_serialization
