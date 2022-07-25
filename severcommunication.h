#ifndef SEVERCOMMUNICATION_H
#define SEVERCOMMUNICATION_H

#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QProgressDialog>
#include <QUrl>

class SeverCommunicationData;

class SeverCommunication : public QObject
{
    Q_OBJECT
public:
    explicit SeverCommunication(QObject *parent = nullptr);
    void startRequest(const QUrl &requestedUrl);
    SeverCommunication(const SeverCommunication &);
    SeverCommunication &operator=(const SeverCommunication &);
    ~SeverCommunication();

signals:

private:
    QSharedDataPointer<SeverCommunicationData> data;

private slots:
    void downloadFile();

};

#endif // SEVERCOMMUNICATION_H
