#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QObject>
#include <QTimer>
#include <qDebug>
#include <QWaitCondition>
#include <QMutex>
#include <QtNetwork>
#include <QLocalServer>
#include <testconnection.h>


class TestAgentTest : public QObject
{
    Q_OBJECT

public:
    TestAgentTest();
    ~TestAgentTest();



private slots:
    void testClientServer();
signals:

};

TestAgentTest::TestAgentTest()
{
}

TestAgentTest::~TestAgentTest()
{
    qDebug("********************* destroyed *********************** ");
}

void TestAgentTest::testClientServer()
{
    QThread t;
    TestConnection server;
    //server.moveToThread(&t);
    server.runLocalServer();
    qDebug() << "server is on thread " << server.thread();

    TestConnection client;

}



QTEST_APPLESS_MAIN(TestAgentTest);

#include "tst_testagenttest.moc"
