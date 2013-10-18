#-------------------------------------------------
#
# Project created by QtCreator 2013-10-17T15:30:10
#
#-------------------------------------------------

QT       -= core gui
CONFIG += c++11
QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -Wall -Werror

TARGET = egraphsrv
TEMPLATE = lib

SOURCES += \
    AbstractServer.cxx \
    AbstractFormatDialect.cxx \
    HtmlFormat.cxx \
    AbstractRequest.cxx \
    RequestTypes.cxx \
    AbstractVertexRequest.cxx \
    AbstractEdgeRequest.cxx \
    VertexRequest.cxx

HEADERS += \
    AbstractServer.hxx \
    AbstractFormatDialect.hxx \
    Server.hxx \
    HtmlFormat.hxx \
    AbstractRequest.hxx \
    RequestTypes.hxx \
    AbstractVertexRequest.hxx \
    AbstractEdgeRequest.hxx \
    VertexRequest.hxx

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

unix:!macx: LIBS += -L$$PWD/../build-egraph-Desktop-Debug/ -legraph

INCLUDEPATH += $$PWD/../egraph
DEPENDPATH += $$PWD/../egraph
