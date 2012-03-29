TEMPLATE = subdirs

#CONFIG += ordered

SUBDIRS += \
    BeaconNetworking \
    BeaconConsole \
    BeaconRemoteAgent \
    TestAgent \
    NetworkTrial \
    TestNetworking

TESTSCR.path = c:/bin/
TESTSCR.files = $$PWD/scripts/TestAgent.py
!exists( $$TESTSCR.files ) {
    message("not found")
}

INSTALLS += TESTSCR

#INCLUDEPATH += $$PWD/BeaconNetworking
#DEPENDPATH += $$PWD/BeaconNetworking





