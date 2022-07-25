#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QDebug>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QTimer ScanningFrequency;
    bool isStart;



public:
    MainWindow(QWidget *parent = nullptr);
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
