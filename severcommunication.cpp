#include "severcommunication.h"

class SeverCommunicationData : public QSharedData
{
public:

};

SeverCommunication::SeverCommunication(QObject *parent) : QObject(parent), data(new SeverCommunicationData)
{

}

SeverCommunication::SeverCommunication(const SeverCommunication &rhs) : data(rhs.data)
{

}

SeverCommunication &SeverCommunication::operator=(const SeverCommunication &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

SeverCommunication::~SeverCommunication()
{

}




void SeverCommunication :: downloadFile()
{
//    const QString urlSpec = urlLineEdit->text().trimmed();
//    if (urlSpec.isEmpty())
//        return;

//    const QUrl newUrl = QUrl::fromUserInput(urlSpec);
//    if (!newUrl.isValid()) {
//        QMessageBox::information(this, tr("Error"),
//                                 tr("Invalid URL: %1: %2").arg(urlSpec, newUrl.errorString()));
//        return;
//    }

//    QString fileName = newUrl.fileName();
//    if (fileName.isEmpty())
//        fileName = defaultFileLineEdit->text().trimmed();
//    if (fileName.isEmpty())
//        fileName = defaultFileName;
//    QString downloadDirectory = QDir::cleanPath(downloadDirectoryLineEdit->text().trimmed());
//    if (!downloadDirectory.isEmpty() && QFileInfo(downloadDirectory).isDir())
//        fileName.prepend(downloadDirectory + '/');
//    if (QFile::exists(fileName)) {
//        if (QMessageBox::question(this, tr("Overwrite Existing File"),
//                                  tr("There already exists a file called %1 in "
//                                     "the current directory. Overwrite?").arg(fileName),
//                                  QMessageBox::Yes|QMessageBox::No, QMessageBox::No)
//            == QMessageBox::No)
//            return;
//        QFile::remove(fileName);
//    }

//    file = openFileForWrite(fileName);
//    if (!file)
//        return;

//    downloadButton->setEnabled(false);

//    // schedule the request
//    startRequest(newUrl);


}
void SeverCommunication::startRequest(const QUrl &requestedUrl)
{

}
