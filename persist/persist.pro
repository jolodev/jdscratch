#-------------------------------------------------
#
# Project created by QtCreator 2013-10-14T15:13:31
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = persist
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -Werror -Wall

TEMPLATE = app


SOURCES += main.cxx \
    Tools.cxx \
    AbstractNode.cxx \
    Node.cxx \
    Database.cxx \
    InDatabaseNode.cxx \
    DataType.cxx \
    Schema.cxx \
    Extension.cxx \
    InSchemaNode.cxx \
    Table.cxx \
    InTableNode.cxx \
    TableColumn.cxx

HEADERS += \
    Types.hxx \
    Tools.hxx \
    AbstractNode.hxx \
    AbstractNodeFwd.hxx \
    Node.hxx \
    NodeFwd.hxx \
    Database.hxx \
    DatabaseFwd.hxx \
    InDatabaseNode.hxx \
    DataTypeFwd.hxx \
    DataType.hxx \
    Config.hxx \
    SchemaFwd.hxx \
    Schema.hxx \
    ExtensionFwd.hxx \
    Extension.hxx \
    InSchemaNode.hxx \
    TableFwd.hxx \
    Table.hxx \
    InTableNode.hxx \
    TableColumnFwd.hxx \
    TableColumn.hxx
