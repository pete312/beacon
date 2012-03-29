#ifndef TESTCONNECTION_H
#define TESTCONNECTION_H

#include <QThread>
#include <QMutex>
#include <QThread>
#include <../BeaconNetworking/beaconipc.h>

class TestConnection : public QObject
{
    Q_OBJECT
public:
    TestConnection();
    TestConnection(int count);

    void runLocalServer();
    void run();
    void stop();

    int getCount();
    void startClient();
    void startServer();

    BeaconIPC * _client;
    BeaconIPC * _server;
    QThread * _thread;


private :
    QMutex _mutex;
    volatile bool _stop;
    int _count;

public slots:
    void gotConnect();

signals:

};

#endif // TESTCONNECTION_H
