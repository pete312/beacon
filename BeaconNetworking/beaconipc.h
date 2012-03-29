#ifndef KINGFISHERIPC_H
#define KINGFISHERIPC_H
#include <QObject>
#include <QtNetwork>

class BeaconIPC : public QObject
{
    Q_OBJECT

public:
    BeaconIPC();


    QTcpSocket * connectToServer(const QString & host, uint port);
    QTcpServer * listenOn(quint16 port);


    void open();

    QByteArray readBuff();
    QByteArray waitForInput();
    void writeBuff(const QByteArray & buff);

private:
    QTcpSocket * _socket;
    QTcpServer * _socketServer;
    QTcpSocket * _client;
    quint64 _outLen;
    quint64 _inLen;

public slots:
    void readIt();
    void newConnection();

signals:
    void bufferNotEmpty();
    void newClientConnected();

};

#endif // KINGFISHERIPC_H
