#-------------------------------------------------
#
# Project created by QtCreator 2011-10-06T11:33:09
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = BeaconRemoteAgent
CONFIG   += console
CONFIG   -= app_bundle


TEMPLATE = app

SOURCES += main.cpp \
    beacon_remote_agent.cpp \
    applicationsettings.cpp \
    agentbase.cpp

HEADERS += \
    beacon_remote_agent.h \
    applicationsettings.h \
    agentbase.h

RESOURCES += \
    files.qrc

INSTALLS += TARGET

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../BeaconNetworking/release/ -lBeaconNetworking
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../BeaconNetworking/debug/ -lBeaconNetworking
else:symbian: LIBS += -lBeaconNetworking
else:unix: LIBS += -L$$OUT_PWD/../BeaconNetworking/ -lBeaconNetworking

INCLUDEPATH += $$PWD/../BeaconNetworking
DEPENDPATH += $$PWD/../BeaconNetworking
