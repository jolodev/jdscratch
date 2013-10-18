include(../../../config.pri)

TEMPLATE = app
TARGET = egraphsrvtest
DESTDIR = ../../../build/bin

INCLUDEPATH += $$PWD/../../lib

DEPENDPATH += $$PWD/../../lib/egraph
DEPENDPATH += $$PWD/../../lib/egraphsrv

unix:!macx: LIBS += -lboost_serialization -L$$OUT_PWD/../../../build/lib -legraph -legraphsrv

HEADERS += \
    Config.hxx

SOURCES += main.cpp
