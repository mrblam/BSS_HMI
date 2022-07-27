#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QDebug>
#include <QTimer>
#include "interprocesscom.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QTimer ScanningFrequency;
    bool isStart;
    interprocesscom *ICP;


public:
    MainWindow(interprocesscom *p_inter,QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openCurrentVersion();

    void closeCurrentVersion();

    void openNewVersion();
    void scanning();




private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
