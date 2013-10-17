TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
QMAKE_CXXFLAGS += -Werror -Wall
QMAKE_CXX = clang++

SOURCES += main.cpp

unix:!macx: LIBS += -L$$PWD/../build-egraph-Desktop-Debug/ -legraph
unix:!macx: LIBS += -lboost_serialization

INCLUDEPATH += $$PWD/../egraph
DEPENDPATH += $$PWD/../egraph

HEADERS += \
    Config.hxx
