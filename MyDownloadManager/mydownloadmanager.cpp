#include "mydownloadmanager.h"

MyDownloadManager::MyDownloadManager(QObject *parent) :
    QObject(parent)
{
    qDebug()<<"Inside MyDownloadManager constructor ";
    manager = new QNetworkAccessManager;
    bytesDownloadedAtPause = 0;    
}

void MyDownloadManager::startDownload(QUrl &url)
{
    newurl = url ;
    qDebug()<<"Inside The startDownload Function & the  URL is : "<< newurl;
    request = new QNetworkRequest(newurl);
    reply = manager->get(*request);
    connect(reply, SIGNAL(finished()),this,SLOT(downloadFinished()));
}

QString MyDownloadManager::saveFileName(QUrl &url)
{
    QString path = url.path();
    qDebug()<<"The Path is : "<< path;
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "download";

    if (QFile::exists(basename)) {        
        int i = 0;
        basename += '.';
        while (QFile::exists(basename + QString::number(i)))
            ++i;

        basename += QString::number(i);
    }

    return basename;
}

bool MyDownloadManager::saveToDisk(QString &filename, QIODevice *data)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        fprintf(stderr, "Could not open %s for writing: %s\n",
                qPrintable(filename),
                qPrintable(file.errorString()));
        return false;
    }

    file.write(data->readAll());
    file.close();

    return true;
}

void MyDownloadManager::downloadFinished()
{
    qDebug()<<"Hitten the Download Finished Slot";
    QUrl url = reply->url();
    if (reply->error()) {
        fprintf(stderr, "Download of %s failed: %s\n",
                url.toEncoded().constData(),
                qPrintable(reply->errorString()));
    } else {
        QString filename = saveFileName(url);
        if (saveToDisk(filename, reply))
            printf("Download of %s succeded (saved to %s)\n",
                   url.toEncoded().constData(), qPrintable(filename));
    }
}

void MyDownloadManager::cancelDownload()
{
    qDebug()<<"Inside the Cancel Download Slot";
    reply->abort();
}

void MyDownloadManager::PauseDownload()
{
    qDebug()<<"Inside the Download Manager Pause Download Slot";
    if(reply == 0)
    {
        return;
    }
    disconnect(reply,SIGNAL(finished()),this,SLOT(downloadFinished()));
    reply->abort();
    WriteFile();    
    reply = 0;
}

void MyDownloadManager::ResumeDownload()
{
    qDebug()<<"Inside the Download Manager Resume Download Slot";
    /*bytesDownloadedAtPause = m_file->size();
    qDebug()<<"Downloadsize"<<bytesDownloadedAtPause / 1024;
    QByteArray rangeHeaderValue = "bytes=" + QByteArray::number(bytesDownloadedAtPause) + "-";
    request->setRawHeader("Range",rangeHeaderValue);
    startRequest(request);*/
}


void MyDownloadManager::startRequest(QNetworkRequest *req)
{
    reply = manager->get(*req);

    connect(reply, SIGNAL(readyRead()),this, SLOT(WriteFile()));
    connect(reply,SIGNAL(finished()),this,SLOT(downloadFinished()));    
}

void MyDownloadManager::WriteFile()
{
    QUrl url = reply->url();
    QString filename = saveFileName(url);
    m_file = new QFile(filename) ;
    if(!m_file->open(QIODevice::WriteOnly))
    {         
        qDebug()<<"Unable to save the file ";
         delete m_file;
         m_file = 0;
         return;
    }
    if (m_file)
    {
        m_file->write(reply->readAll());
        qDebug()<<"The file has been saved succesfully after pause";
    }
}
