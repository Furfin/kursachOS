#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <QTextEdit>
#include <thread>
#include <QtConcurrent/QtConcurrent>
#include <QtCore>
#include <QtNetwork>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    int PORT;
    bool *c = (bool*)malloc(sizeof(bool) + 10);
    std::string client_request;
    std::thread th;
    QTcpSocket *socket;
    ~MainWindow();

private slots:
    void onServ1ButtonClicked();
    void onServ2ButtonClicked();
    void onMSG1Clicked();
    void onMSG2Clicked();
    void onBOTHClicked();
    void onStopCLicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
