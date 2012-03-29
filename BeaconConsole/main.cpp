#include <QtGui/QApplication>
#include "beacon.h"


// Author : Peter Moore
// Development start : Oct 2011

// The Beacon Monitoring Application is licensed under the GPL 3.0.

// The Beacon Remote Agent is licensed under the LGPL 2.1 which allows you
// to develop proprietary standalone remote agents with no obligation to release
// the source.

// The AgentBase library is also licensed unser the LGPL 2.1 which allows
// development of specialized embedded agents within proprietary applications
// with no obligation to release the source.

// Above all, have fun.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Beacon w;
    w.show();

    return a.exec();
}
