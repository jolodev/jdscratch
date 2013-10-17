TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -Wall -Werror

SOURCES += \
    main.cxx \
    Graph.cxx \
    AbstractNode.cxx \
    AbstractEdge.cxx \
    AbstractNodePayload.cxx \
    NodePayload.cxx \
    Edge.cxx \
    ValueNodePayload.cxx \
    Tools.cxx \
    FossilType.cxx \
    EdgeTypes.cxx \
    Fossil.cxx

HEADERS += \
    Types.hxx \
    Graph.hxx \
    AbstractNode.hxx \
    AbstractEdge.hxx \
    Node.hxx \
    AbstractNodePayload.hxx \
    NodePayload.hxx \
    Edge.hxx \
    ValueNodePayload.hxx \
    Tools.hxx \
    FossilType.hxx \
    EdgeTypes.hxx \
    Fossil.hxx

