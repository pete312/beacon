#include "beacon_remote_agent.h"
#include <QFile>
#include <QDebug>
#include "../BeaconNetworking/beaconipc.h"


BeaconRemoteAgent::BeaconRemoteAgent() :
    _proc(0),
    _ended(true),
    _UDPClientMap()
{
}


void BeaconRemoteAgent::setUDPPort(const QString &host, const uint port)
{
    QString key = (tr("%s:%d").arg(host).arg(port)).toAscii();
    //_UDPClientMap[key] = new UDPAgent(host, port);
}




void BeaconRemoteAgent::start(const QString &command)
{

    QStringList args;
    args << tr("BeaconRemoteAgent %1 %2").arg( "call" ).arg(22);
    if ( _ended ){
        if (_proc == 0){
            _proc = new QProcess;
        }
        _ended = false;
        connect(_proc, SIGNAL(readyReadStandardOutput()), this, SLOT(readStdOut()) );
        connect(_proc, SIGNAL(stateChanged(QProcess::ProcessState)), this, SLOT(changedState(QProcess::ProcessState)) );
        connect(_proc, SIGNAL(finished(int)), this, SLOT(hasEnded(int)));
        connect(_proc, SIGNAL(started()), this, SLOT(started()));
        qDebug("starting it");
        QString cmd2(command);
        cmd2.prepend("C:/bin/");
        _proc->start(cmd2,args);
        dumpIt(cmd2);
    }
    else {
        qWarning("Process already running.");
    }

}

void BeaconRemoteAgent::dumpIt(const QString & filename )
{

    QString file2(filename);

    qDebug() << filename << " becomes " << file2;
    QFile in(file2);
    if( !in.exists() ){
        qErrnoWarning("Cant start agent");
        return;
    }
    in.open(QIODevice::ReadOnly | QIODevice::Text);
    qDebug() << "++++++++++++++++++++";
    while (!in.atEnd()) {
        QByteArray buf = in.readLine();
        qDebug() << buf ;
    }
    qDebug() << "-------------------";
}

void BeaconRemoteAgent::stop()
{
    done();
}

void BeaconRemoteAgent::readStdOut()
{
    QByteArray buffer;
    buffer = _proc->readAllStandardOutput();

    qDebug(buffer.data());
}

void BeaconRemoteAgent::hasEnded(int code)
{
    qDebug() << "process ended with" << (code ? "CRASH" : "OK") ;
    _ended = true;
    done();
}


void BeaconRemoteAgent::changedState(QProcess::ProcessState state)
{
    QString status;


    qDebug() << "change" << state ;
}

void BeaconRemoteAgent::started()
{
    qDebug() << "process started";
}



