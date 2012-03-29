#-------------------------------------------------
#
# Project created by QtCreator 2011-10-01T22:42:29
#
#-------------------------------------------------

QT       += core gui network

TARGET = BeaconConsole
TEMPLATE = app


SOURCES += main.cpp\
        beacon.cpp \
    about.cpp \
    appsettings.cpp \
    global_options.cpp \
    query.cpp

HEADERS  += beacon.h \
    about.h \
    appsettings.h \
    global_options.h \
    query.h \
    metric.h

FORMS    += beacon.ui \
    about.ui \
    global_options.ui

OTHER_FILES += \
    images/FinalLogo.png

RESOURCES += \
    beacon.qrc














