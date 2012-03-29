#-------------------------------------------------
#
# Project created by QtCreator 2011-10-23T13:51:47
#
#-------------------------------------------------

QT       += testlib
QT += network

QT       -= gui

TARGET = tst_testagenttest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_testagenttest.cpp \
    testconnection.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../BeaconNetworking/release/ -lBeaconNetworking
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../BeaconNetworking/debug/ -lBeaconNetworking
else:unix:!symbian: LIBS += -L$$OUT_PWD/../BeaconNetworking/ -lBeaconNetworking

INCLUDEPATH += $$PWD/../BeaconNetworking
DEPENDPATH += $$PWD/../BeaconNetworking

message( project working dir is $$PWD )
message( include path is $$INCLUDEPATH )
message ( depend path is $$DEPENDPATH )

HEADERS += \
    testconnection.h


