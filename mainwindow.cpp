#include "mainwindow.h"
#include "ui_mainwindow.h"

QProcess *CurrentVersion = new QProcess();
QProcess *NewVersion = new QProcess();


QProcess::ProcessError errorCode;



MainWindow::MainWindow(interprocesscom *p_inter,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->ICP = p_inter;


    ui->setupUi(this);
    this->isStart = false;
    connect (&ScanningFrequency, &QTimer::timeout, this,&MainWindow::scanning);
    ScanningFrequency.start(5000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openCurrentVersion()
{
    QString currentProgram = "/home/hoanpx/Desktop/build-bss-hmi-Desktop-Release/bss-hmi";
    CurrentVersion->start(currentProgram);
    qDebug() << "show" << CurrentVersion->state();
}


void MainWindow::closeCurrentVersion()
{
    CurrentVersion->kill();
    qDebug() <<  "clicked "  ;
}



void MainWindow::openNewVersion()
{
    QString newProgram = "/home/hoanpx/Selex/BSS/BSS-HMI/HMI-V3/bss-hmi-qt/build-bss-hmi-Desktop-Debug/bss-hmi";
    NewVersion->start(newProgram);
    //CurrentVersion = NewVersion;
    qDebug() <<  "Run new version "  ;
}

void MainWindow::scanning()
{
    qDebug() << "show" << CurrentVersion->state();
    this->isStart = ICP->getReStart();
    qDebug() <<ICP->getReStart() <<this->isStart;
//return;
    if(CurrentVersion->state() == 0 || this->isStart == true){
        this->openCurrentVersion();

        qDebug() <<  "restart bss-hmi "  ;
        return;
    }



}




