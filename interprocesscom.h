#ifndef INTERPROCESSCOM_H
#define INTERPROCESSCOM_H

#include <QDialog>
#include <QLabel>
#include <QDataStream>
#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QMessageBox>
#include <QNetworkInterface>
#include <QTimer>

// IPC app1 (server) --- HMI (client)
#define TCP_SERVER_PORT_WRITE 12345
// IPC app1 (client) --- HMI (server)
#define TCP_SERVER_PORT_READ  54321


class interprocesscom : public QObject
{
    Q_OBJECT
public:
    interprocesscom(QObject *parent = nullptr);
    static interprocesscom* getInterProcessCom();
    bool reStart;
    bool getReStart();
private slots:
    void sendMessage();
    void readMessage();
    void connectToBssHmi();
private:
     QTimer heartbeatsend;
    void initServer();
    QString ipAddress;
    QLabel *statusLabel = nullptr;
    QTcpServer *tcpServer = nullptr;
    QList<QString> fortunes;
    QTcpSocket * serverRead;

};

#endif // INTERPROCESSCOM_H
