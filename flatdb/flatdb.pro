#-------------------------------------------------
#
# Project created by QtCreator 2013-10-14T16:59:25
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = flatdb
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11
QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -Wall -Werror

TEMPLATE = app


SOURCES += main.cxx \
    Tools.cxx \
    Database.cxx \
    AbstractNode.cxx \
    InDatabaseNode.cxx \
    DataType.cxx \
    Schema.cxx \
    InSchemaNode.cxx \
    Extension.cxx \
    Table.cxx \
    InTableNode.cxx \
    TableColumn.cxx \
    ColumnRoles.cxx \
    AbstractDbCreator.cxx \
    AbstractSqlDialect.cxx \
    PostgresDialect.cxx

HEADERS += \
    Types.hxx \
    Tools.hxx \
    Database.hxx \
    DatabaseFwd.hxx \
    AbstractNode.hxx \
    AbstractNodeFwd.hxx \
    Node.hxx \
    Config.hxx \
    InDatabaseNode.hxx \
    DataTypeFwd.hxx \
    DataType.hxx \
    SchemaFwd.hxx \
    Schema.hxx \
    InSchemaNode.hxx \
    ExtensionFwd.hxx \
    Extension.hxx \
    TableFwd.hxx \
    Table.hxx \
    InTableNode.hxx \
    TableColumnFwd.hxx \
    TableColumn.hxx \
    ColumnRoles.hxx \
    AbstractDbCreator.hxx \
    DbCreator.hxx \
    AbstractSqlDialect.hxx \
    PostgresDialect.hxx
