include($$PWD/../../../config.pri)

QT              -= core gui

CONFIG          += console
CONFIG          -= app_bundle
CONFIG          -= qt

TEMPLATE        = lib
TARGET          = egraph
DESTDIR         = ../../../build/lib

unix:!macx: LIBS += -lboost_serialization

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

