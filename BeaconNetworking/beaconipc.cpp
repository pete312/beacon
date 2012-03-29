#include "beaconipc.h"
#include <QDebug>



BeaconIPC::BeaconIPC()
{
}


QTcpSocket * BeaconIPC::connectToServer(const QString &host, uint port)
{
    qDebug(host.toAscii());
    this->dumpObjectTree();
    QTcpSocket * socket = new QTcpSocket;
    socket->abort();
    socket->connectToHost(host,port);
    QObject::connect(socket, SIGNAL(readyRead()) , this, SLOT(readIt()));
    _client = socket;
    return socket;
}

QTcpServer * BeaconIPC::listenOn(quint16 port)
{

    this->dumpObjectTree();
    QTcpServer * tcpServer = new QTcpServer;
    if (!tcpServer->listen(QHostAddress::LocalHost,port)) {
        qFatal("error binding to port ");
        return NULL;
    }

    _socketServer = tcpServer;
    connect(_socketServer, SIGNAL(newConnection()), SLOT(newConnection()));

    return tcpServer;

}



void BeaconIPC::readIt()
{

    qDebug() << "Reading incomming server message";

    qDebug() << "read" << _socket->readAll();
    emit newClientConnected();
}

void BeaconIPC::open()
{

}


QByteArray BeaconIPC::waitForInput()
{
    return QByteArray("buffer ");
}

void BeaconIPC::writeBuff(const QByteArray &buff)
{
    _outLen = _socket->write(buff);
}


void BeaconIPC::newConnection()
{
    qDebug() << "got new connection";
    _client = _socketServer->nextPendingConnection();
    _client->dumpObjectTree();
    qDebug() << this;
    QByteArray buf = "this is a test string\r\n";
    _client->write(buf);
    _client->flush();
    _client->waitForBytesWritten();

    connect(_client,SIGNAL(readyRead()), this, SLOT(readIt()));
    qDebug() << "wrote" << buf.length() <<  "bytes" ;
}




