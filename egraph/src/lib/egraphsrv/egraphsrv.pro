include($$PWD/../../../config.pri)

QT              -= core gui

CONFIG          += console
CONFIG          -= app_bundle
CONFIG          -= qt

TARGET          = egraphsrv
TEMPLATE        = lib
DESTDIR         = ../../../build/lib

unix:!macx: LIBS += -L$$OUT_PWD/../../../build/lib -legraph

DEPENDPATH += $$PWD/../egraph

INCLUDEPATH += $$PWD/..

SOURCES += \
    AbstractFormatDialect.cxx \
    HtmlFormat.cxx \
    AbstractFormater.cxx

HEADERS += \
    AbstractFormatDialect.hxx \
    HtmlFormat.hxx \
    AbstractFormater.hxx \
    Formater.hxx

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
