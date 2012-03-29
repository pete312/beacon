#include <QtCore/QCoreApplication>
#include <beacon_remote_agent.h>
#include <cstdlib>
#include <QObject>

// The Beacon Monitoring Application is licensed under the GPL 3.0.

// The Beacon Remote Agent is licensed under the LGPL 2.1 which allows you
// to develop proprietary standalone remote agents with no obligation to release
// the source.

// The AgentBase library is also licensed unser the LGPL 2.1 which allows
// development of specialized embedded agents within proprietary applications
// with no obligation to release the source.

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BeaconRemoteAgent *ra = new BeaconRemoteAgent;
    BeaconRemoteAgent *ra2 = new BeaconRemoteAgent;
    QObject::connect(ra, SIGNAL(done()), &a, SLOT( quit() ));

    QObject::connect(ra2, SIGNAL(done()), &a, SLOT( quit() ));

    //ra2->start("TestAgent.py");
    ra->start("test.bat");

    return a.exec();
}

