#include "mainwindow.h"

#include <QApplication>
#include <interprocesscom.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("/home/hoanpx/Pictures/images.jpeg"));
    interprocesscom *server = new interprocesscom();

    MainWindow w(server);
    w.show();
    return a.exec();
}
