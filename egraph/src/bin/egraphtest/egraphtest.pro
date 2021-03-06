include($$PWD/../../../config.pri)

DESTDIR     = ../../../build/bin

TEMPLATE    = app
TARGET      = egraphsrvtest

INCLUDEPATH += $$PWD/../../lib

DEPENDPATH += $$PWD/../../lib/egraph
DEPENDPATH += $$PWD/../../lib/egraphsrv

unix:!macx: LIBS += -lboost_serialization -L$$OUT_PWD/../../../build/lib -legraph -legraphsrv

HEADERS += \
    Config.hxx

SOURCES += \
    main.cxx
