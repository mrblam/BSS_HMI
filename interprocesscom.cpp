#include "interprocesscom.h"

interprocesscom::interprocesscom(QObject *parent) : QObject(parent)
{
    tcpServer = new QTcpServer(this);
    serverRead = new QTcpSocket(this);
    if (!this->tcpServer->listen(QHostAddress::Any,TCP_SERVER_PORT_WRITE))
    {
        qDebug() << tr("Unable to start the server: %1.").arg(tcpServer->errorString()) ;
        return;
    }

#if 0 // get random server port
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address

    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
             qDebug()<< "dia chi ip server " << ipAddress;
            break;
        }

    }
    // if we did not find one, use IPv4 localhost
    if (this->ipAddress.isEmpty())
        this->ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
#endif

    qDebug() << "  port is " << tcpServer->serverPort();
    fortunes << tr("You've been leading a dog's life. Stay off the furniture.");

    connect(tcpServer, &QTcpServer::newConnection, this, &interprocesscom::sendMessage);
    connect(serverRead, &QIODevice::readyRead,this,&interprocesscom::readMessage);
    connect(&heartbeatsend,&QTimer::timeout,this,&interprocesscom::connectToBssHmi);
    heartbeatsend.start(1000);
    }

void interprocesscom::sendMessage()
{
//      QByteArray block;
//      QDataStream out(&block, QIODevice::WriteOnly);
//      out.setVersion(QDataStream::Qt_5_0);

//      out << fortunes;
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    clientConnection->write("app 1 gui diii ");
    qDebug() << "server send" << clientConnection;
//      connect(clientConnection, &QAbstractSocket::disconnected,
//            clientConnection, &QObject::deleteLater);
//      clientConnection->flush();
//      clientConnection->write(block);
//      qDebug() << T(clientConnection);
//      clientConnection->disconnectFromHost();
}

void interprocesscom::readMessage()
{
    qDebug() << "co tin hieu readyRead,du lieu nhan duoc la : ";
    serverRead->waitForReadyRead(3000);
    qDebug() << "Reading : " << serverRead->bytesAvailable();
    qDebug() << serverRead->readAll();
    serverRead->close();
}
void interprocesscom::connectToBssHmi()
{
    serverRead->abort();
    serverRead->connectToHost("localhost",TCP_SERVER_PORT_READ);
    if(serverRead->waitForConnected(3000))
    {
        qDebug() << "bss-hmi connected " ;
    }
    else
    {
        qDebug() << "ko ket noi" ;
    }
}
