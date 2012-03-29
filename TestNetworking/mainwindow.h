#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <beaconipc.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_buttonStartClient_clicked();
    void on_buttonStartServer_clicked();
    void newClientConnected();
    void displayMessage();



private:
    Ui::MainWindow *ui;

    BeaconIPC * _server;
    BeaconIPC * _client;
};

#endif // MAINWINDOW_H
