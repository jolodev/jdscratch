include($$PWD/../../../config.pri)

TARGET = egraphsrv
TEMPLATE = lib
DESTDIR = ../../../build/lib

unix:!macx: LIBS += -L$$OUT_PWD/../../../build/lib -legraph

DEPENDPATH += $$PWD/../egraph

INCLUDEPATH += $$PWD/..

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
