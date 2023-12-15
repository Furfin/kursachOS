#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setText("");
    this->socket = new QTcpSocket(this);

    connect(ui->Serv1Button, SIGNAL(released()), this,  SLOT(onServ1ButtonClicked()));
    connect(ui->Serv2Button, SIGNAL(released()), this,  SLOT(onServ2ButtonClicked()));
    connect(ui->msg1, SIGNAL(released()), this,  SLOT(onMSG1Clicked()));
    connect(ui->msg2, SIGNAL(released()), this,  SLOT(onMSG2Clicked()));
    connect(ui->bbPushButton, SIGNAL(released()), this,  SLOT(onBOTHClicked()));
    connect(ui->stopB,SIGNAL(released()), this,  SLOT(onStopCLicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onServ1ButtonClicked() {
    if(socket->isOpen())
            socket->close();
    ui->textEdit->setText("Connecting Server 1...");
    this->PORT = 8080;
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::onServ2ButtonClicked() {
    if(socket->isOpen())
            socket->close();
    ui->textEdit->setText("Connecting Server 2...");
    this->PORT = 8081;
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::onMSG1Clicked() {
    this->client_request = "11";
    socket->connectToHost(QHostAddress::LocalHost,this->PORT);
    if(socket->waitForConnected())
        ui->textEdit->setText("Connected");
    else{
        QMessageBox::critical(this,"QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
        ui->stackedWidget->setCurrentIndex(0);
        return;
    }
    socket->write(this->client_request.c_str(),qstrlen(this->client_request.c_str()));
    socket->flush();

    ui->textEdit->setText(socket->read(100));

}
void MainWindow::onMSG2Clicked() {
    this->client_request = "21";
    socket->connectToHost(QHostAddress::LocalHost,this->PORT);
    if(socket->waitForConnected())
        ui->textEdit->setText("Connected");
    else{
        QMessageBox::critical(this,"QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
        ui->stackedWidget->setCurrentIndex(0);
        return;
    }
    socket->write(this->client_request.c_str(),qstrlen(this->client_request.c_str()));
    socket->flush();


    ui->textEdit->setText(socket->read(100));

}
void MainWindow::onBOTHClicked() {
    this->client_request = "01";
    socket->connectToHost(QHostAddress::LocalHost,this->PORT);
    if(socket->waitForConnected())
        ui->textEdit->setText("Connected");
    else{
        QMessageBox::critical(this,"QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
        ui->stackedWidget->setCurrentIndex(0);
        return;
    }
    socket->write(this->client_request.c_str(),qstrlen(this->client_request.c_str()));
    socket->flush();


    ui->textEdit->setText(socket->read(100));

}

void MainWindow::onStopCLicked() {
    ui->stackedWidget->setCurrentIndex(0);
}



