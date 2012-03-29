#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonStartServer_clicked()
{
    _server = new BeaconIPC;
    connect(_server, SIGNAL(newClientConnected()), this, SLOT( newClientConnected() ) );
    _server->listenOn(ui->lineEditServerPort->text().toUInt());

}



void MainWindow::newClientConnected()
{
    qDebug() << "Connection request:" ;
}

void MainWindow::displayMessage()
{

}

void MainWindow::on_buttonStartClient_clicked()
{
    _client = new BeaconIPC;
    connect(_client, SIGNAL(connectToServer()), this, SLOT(connectToServer()));
    _client->connectToServer(ui->lineEditHostname->text(), ui->lineEditClientPort->text().toUInt());


}

//void MainWindow::on_pushButtonClientSend_clicked()
//{
//    //ui->plainTextEditClient
//}
