#include "beacon.h"
#include "ui_beacon.h"
#include <about.h>
#include <QMessageBox>
#include <QProcess>
#include <global_options.h>
#include <QDebug>


Beacon::Beacon(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Beacon)
{
    ui->setupUi(this);
    Init();
}

Beacon::~Beacon()
{
    delete ui;
}

void Beacon::Init()
{
    _settings = new AppSettings;
    ui->lineEdit_AgentPath->setText(tr("C:/src/Beacon.build/BeaconRemoteAgent/debug/"));
    ui->lineEdit_AgentName->setText(tr("BeaconRemoteAgent.exe"));

}


void Beacon::on_actionAbout_triggered()
{
    About *about = new About(this);

    about->show();
    about->exec();

    delete about;
}

void Beacon::pushButton_clicked()
{
    ui->tableAlerts->setToolTip("this is a test widget");
    ui->tableAlerts->setColumnCount(3);
    for (int i = 0 ; i < 6000; ++i){
        ui->tableAlerts->setRowCount(i+1);
        QTableWidgetItem *w = new QTableWidgetItem();
        QTableWidgetItem *w1 = new QTableWidgetItem();
        QTableWidgetItem *w2 = new QTableWidgetItem();
        w->setText(tr("%1").arg(i));
        w1->setText(tr("%1:%1").arg(i));
        w2->setText(tr("%1:%1:%1").arg(i));
        ui->tableAlerts->setItem(i,0,w);
        ui->tableAlerts->setItem(i,1,w1);
        ui->tableAlerts->setItem(i,2,w2);

    }
}

void Beacon::on_actionExternal_Agent_triggered()
{

}

void Beacon::ShowGlobalOptions(){

    GlobalOptions *options = new GlobalOptions(this , _settings);
    options->show();
    options->exec();

    delete options;
}


void Beacon::on_actionOptions_triggered()
{
    this->ShowGlobalOptions();
}

void Beacon::on_button_StartAgent_clicked()
{
    _agentProcess = new QProcess(this);

    qDebug("starting an agent");

    QStringList args;
    args << "howdy";
    QString agent = ui->lineEdit_AgentPath->text();
    agent.append("/").append( "BeaconRemoteAgent.exe"); //ui->lineEdit_AgentName);
    connect( _agentProcess, SIGNAL(finished(int)) , this, SLOT(agentClosed(int)));
    connect( _agentProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(readStdOut()));
    connect( _agentProcess, SIGNAL(readyReadStandardError()), this, SLOT(readStdErr()));
    _agentProcess->setWorkingDirectory(ui->lineEdit_AgentPath->text());

    _agentProcess->start( agent , args );

    ui->textOutput->setPlainText(agent);
    ui->textOutput->setPlainText(tr("started"));


}

void Beacon::agentClosed(int exitCode)
{
    ui->textOutput->setPlainText(
        tr("Has exited with an %1" ).arg( exitCode ? "Error" : "OK" )
    );
}


void Beacon::readStdOut()
{
    qDebug("Has output");
    QByteArray out = _agentProcess->readAllStandardOutput();
    //qDebug() << out.;
   // ui->textOutput->setPlainText(tr("output %1").arg(out.data()));
}

void Beacon::readStdErr()
{
    qDebug("Has error output");
    QByteArray out = _agentProcess->readAllStandardError();
    qDebug() << out;
    ui->textOutput->setPlainText(tr("Err output %1").arg(out.data()));
}
