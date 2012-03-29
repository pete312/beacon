#include "testconnection.h"
#include <QWaitCondition>
#include <QThread>
#include <QDebug>

TestConnection::TestConnection() : _count(0)
{
    _thread = new QThread;
    _thread->start();
    this->moveToThread(_thread);
}

TestConnection::TestConnection(int count) : _count(count)
{
}


void TestConnection::runLocalServer()
{
    startServer();
    //qDebug() << server << QThread::currentThread();

}

//void TestConnection::run()
//{

//    _stop = false;
//    _mutex.lock();

//    while (!_stop) {

//        QWaitCondition timed;
//        timed.wait(&_mutex, 1000);
//        qDebug("a tick.");
//        if (--_count < 0)
//        {
//            break;
//        }

//    }

//    _mutex.unlock();

//}

void TestConnection::stop()
{
    _stop = true;
}

int TestConnection::getCount(){
    return _count;
}

void TestConnection::startClient()
{
    _client = new BeaconIPC;

}

void TestConnection::startServer()
{
    _server = new BeaconIPC;
    _server->listenOn(1234);

    //connect(_server, SIGNAL(newClientConnected()));
}


void TestConnection::gotConnect()
{
}
