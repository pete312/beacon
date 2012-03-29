#include "global_options.h"
#include "ui_global_options.h"
#include <QFileDialog>
//#include <stdio.h>


GlobalOptions::GlobalOptions(QWidget *parent, AppSettings *settings) :
    QDialog(parent),
    _settings(settings),
    ui(new Ui::global_options)
{
    //TODO need to add svn repo location for configuration.

    ui->setupUi(this);
    QString rettext("");
    if (settings->getValue("_DBFile", rettext )){
        ui->entryDBFile->insert(rettext);
    }

    if (settings->getValue("_PrimaryHost", rettext )){
        ui->entryPrimaryHost->insert(rettext);
    }

    if (settings->getValue("_AuxiliaryHost", rettext )){
        ui->entryAuxiliaryHost->insert(rettext);
    }

}

GlobalOptions::~GlobalOptions()
{
    delete ui;
}

void GlobalOptions::on_pushFileBrowse_clicked()
{
    QFileDialog *f = new QFileDialog;

    QString rettext("");
    if (_settings->getValue("_DBFile", rettext )){
        f->selectFile(rettext);
    }

    f->show();
    if (f->exec()){
        QStringList l = f->selectedFiles();
        _settings->setValue("_DBFile", l.first());
        ui->entryDBFile->setText(l.first());
    }
    delete f;
}

void GlobalOptions::on_entryPrimaryHost_editingFinished()
{
    _settings->setValue("_PrimaryHost", ui->entryPrimaryHost->text());
}

void GlobalOptions::on_entryAuxiliaryHost_editingFinished()
{
    _settings->setValue("_AuxiliaryHost", ui->entryAuxiliaryHost->text());
}

void GlobalOptions::on_entryDBFile_editingFinished()
{
    _settings->setValue("_DBFile", ui->entryDBFile->text());
}
