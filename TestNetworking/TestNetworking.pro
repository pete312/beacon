#-------------------------------------------------
#
# Project created by QtCreator 2011-11-15T11:36:03
#
#-------------------------------------------------

QT       += core gui network

TARGET = TestNetworking
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../BeaconNetworking/release/ -lBeaconNetworking
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../BeaconNetworking/debug/ -lBeaconNetworking
else:symbian: LIBS += -lBeaconNetworking
else:unix: LIBS += -L$$OUT_PWD/../BeaconNetworking/ -lBeaconNetworking

INCLUDEPATH += $$PWD/../BeaconNetworking
DEPENDPATH += $$PWD/../BeaconNetworking

