#ifndef KINGFISHER_H
#define KINGFISHER_H

#include <QMainWindow>
#include <appsettings.h>
#include <QProcess>

namespace Ui {
    class Beacon;
}

class Beacon : public QMainWindow
{
    Q_OBJECT

public:
    explicit Beacon(QWidget *parent = 0);
    ~Beacon();

    void ShowGlobalOptions();

private:
    Ui::Beacon *ui;
    void Init();

    AppSettings * _settings;
    QProcess * _agentProcess;

public slots:
    void agentClosed(int exitCode);
    void readStdOut();
    void readStdErr();
    void pushButton_clicked();


private slots:
    void on_actionAbout_triggered();

    void on_actionExternal_Agent_triggered();
    void on_actionOptions_triggered();
    void on_button_StartAgent_clicked();



};

#endif // KINGFISHER_H
