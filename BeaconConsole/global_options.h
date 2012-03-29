#ifndef GLOBAL_OPTIONS_H
#define GLOBAL_OPTIONS_H

#include <QDialog>
#include <appsettings.h>

namespace Ui {
    class global_options;
}

class GlobalOptions : public QDialog
{
    Q_OBJECT

public:
    explicit GlobalOptions(QWidget *parent = 0, AppSettings *settings = 0);
    ~GlobalOptions();

private slots:
    void on_pushFileBrowse_clicked();

    void on_entryAuxiliaryHost_editingFinished();

    void on_entryPrimaryHost_editingFinished();

    void on_entryDBFile_editingFinished();

private:
    AppSettings * _settings;
    Ui::global_options *ui;
    std::string _pri_host;
    std::string _aux_host;

};

#endif // GLOBAL_OPTIONS_H
