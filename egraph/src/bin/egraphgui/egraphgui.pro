include($$PWD/../../../config.pri)

DESTDIR = ../../../build/bin

QT       += core gui widgets

TARGET = egraphgui
TEMPLATE = app

INCLUDEPATH += $$PWD/../../lib

DEPENDPATH += $$PWD/../../lib/egraph
DEPENDPATH += $$PWD/../../lib/egraphsrv

unix:!macx: LIBS += -lboost_serialization -L$$OUT_PWD/../../../build/lib -legraph -legraphsrv

SOURCES += main.cxx \
        MainWindow.cxx \
    GraphBrowser.cxx

HEADERS  += MainWindow.hxx \
    Config.hxx \
    GraphBrowser.hxx

FORMS    +=
