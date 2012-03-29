#-------------------------------------------------
#
# Project created by QtCreator 2011-10-13T09:32:48
#
#-------------------------------------------------

QT       += network

QT      -= gui
QT      += network

TARGET = BeaconNetworking
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    payload.cpp \
    beaconipc.cpp

HEADERS += \
    payload.h \
    beaconipc.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
























