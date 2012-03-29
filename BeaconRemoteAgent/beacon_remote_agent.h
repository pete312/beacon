#ifndef BEACONREMOTEAGENT_H
#define BEACONREMOTEAGENT_H

#include <QObject>
#include <QProcess>
#include <QMap>
#include <QUdpSocket>

class BeaconRemoteAgent : public QObject
{
    Q_OBJECT

public:
    BeaconRemoteAgent();

    void setUDPPort(const QString &host, const uint port);
    void start(const QString &command);
    void stop();

private:
    QProcess * _proc;
    bool _ended;
    QMap<QString,QUdpSocket *> _UDPClientMap; // maps host to a udp socket


    void dumpIt(const QString & filename );

public slots:
    void readStdOut();
    void hasEnded(int code);
    void changedState(QProcess::ProcessState state);
    void started();

signals:
    void done();


};

#endif // BEACONREMOTEAGENT_H
