TEMPLATE = app
TARGET = om
INCLUDEPATH += .
INCLUDEPATH += ./src
CONFIG += c++11
QT += widgets gui sql

QMAKE_CXXFLAGS += -Werror -Wall
QMAKE_CXX = clang++

# Input
SOURCES += src/main.cxx \
    src/MainWindow.cxx \
    src/obj/AbstractObject.cxx \
    src/obj/Object.cxx \
    src/core/OMTools.cxx \
    src/obj/AbstractProperty.cxx \
    src/core/qiostream.cxx \
    src/obj/TestNode.cxx \
    src/db/AbstractDbNode.cxx \
    src/db/Database.cxx \
    src/db/InDatabaseNode.cxx \
    src/db/Schema.cxx \
    src/db/InSchemaNode.cxx \
    src/db/Table.cxx \
    src/orm/Mapper.cxx \
    src/orm/AbstractDbGen.cxx \
    src/orm/AbstractDatabaseDialect.cxx \
    src/orm/PgDialect.cxx \
    src/db/InTableNode.cxx \
    src/db/TableColumn.cxx \
    src/obj/PropertyRole.cxx \
    src/core/DatabaseConnectionData.cxx \
    pgconn/PgConn.cxx

HEADERS += \
    src/MainWindow.hxx \
    src/obj/AbstractObject.hxx \
    src/core/Types.hxx \
    src/obj/Object.hxx \
    src/core/OMTools.hxx \
    src/obj/AbstractObjectFwd.hxx \
    src/obj/AbstractProperty.hxx \
    src/obj/AbstractPropertyFwd.hxx \
    src/obj/Property.hxx \
    src/core/qiostream.hxx \
    src/obj/ObjectFormatter.hxx \
    src/obj/TestNode.hxx \
    src/db/AbstractDbNode.hxx \
    src/db/Database.hxx \
    src/db/InDatabaseNode.hxx \
    src/db/Schema.hxx \
    src/db/InSchemaNode.hxx \
    src/db/Table.hxx \
    src/orm/Mapper.hxx \
    src/db/TableFwd.hxx \
    src/db/AbstractDbNodeFwd.hxx \
    src/orm/AbstractDbGen.hxx \
    src/orm/DbGen.hxx \
    src/orm/AbstractDatabaseDialect.hxx \
    src/orm/PgDialect.hxx \
    src/db/DatabaseFwd.hxx \
    src/db/SchemaFwd.hxx \
    src/db/TableFwd.hxx \
    src/db/InTableNode.hxx \
    src/db/TableColumn.hxx \
    src/obj/PropertyRole.hxx \
    src/core/DatabaseConnectionData.hxx \
    pgconn/PgConn.hxx \
    src/db/TableColumnFwd.hxx \
    src/orm/AbstractTypeTrait.hxx

OTHER_FILES += \
    android/version.xml \
    android/java.pro \
    android/AndroidManifest.xml \
    android/android-libjava.so-deployment-settings.json \
    android/res/values-ro/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-de/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values/strings.xml \
    android/res/values/libs.xml \
    android/res/values-et/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-id/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/layout/splash.xml \
    android/res/values-nl/strings.xml \
    android/res/values-es/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/res/values-pl/strings.xml \
    android/Makefile \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/qtproject/qt5/android/bindings/QtActivity.java \
    android/src/org/qtproject/qt5/android/bindings/QtApplication.java \
    android/READ-THIS-BEFORE-MANUALLY-ADDING-FILES-TO-PACKAGE.txt \
    android/libjava.so
