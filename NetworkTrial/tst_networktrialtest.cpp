#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QDebug>
#include <QTcpSocket>
#include <QTcpServer>

class NetworkTrialTest : public QObject
{
    Q_OBJECT

public:
    NetworkTrialTest();

private:
    QTcpSocket* qTestSocket;
    QTcpSocket* qDummySocket;
    QTcpServer* qDummyServer;

public slots:
    void connectDummyServer();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void sendDataTest();
};

NetworkTrialTest::NetworkTrialTest()
{
}


void NetworkTrialTest::connectDummyServer()
{

    qDebug() << "connection attempt";
    qDummySocket = qDummyServer->nextPendingConnection();

}

void NetworkTrialTest::initTestCase()
{
    qDummySocket = NULL;
    qDummyServer = new QTcpServer();
    connect( qDummyServer, SIGNAL(newConnection()), SLOT(connectDummyServer()) );
    qDummyServer->listen( QHostAddress::LocalHost, 9000 );
    QVERIFY( qDummyServer->isListening() );



    qTestSocket = new QTcpSocket();
    qTestSocket->connectToHost( QHostAddress::LocalHost, 9000 );

    QVERIFY( qTestSocket->waitForConnected( 5000 ) );
    QVERIFY( qTestSocket->state() == QTcpSocket::ConnectedState );
 }

void NetworkTrialTest::cleanupTestCase()
{
}

//void NetworkTrialTest::testCase1()
//{
//    QVERIFY2(true, "Failure");
//}

void NetworkTrialTest::sendDataTest()
{
    qDebug() << "here" <<  qDummySocket;
    //QVERIFY( qDummySocket != NULL );
}

//QTEST_APPLESS_MAIN(NetworkTrialTest);
QTEST_MAIN(NetworkTrialTest);

#include "tst_networktrialtest.moc"
