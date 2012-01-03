#ifndef MYDOWNLOADMANAGER_H
#define MYDOWNLOADMANAGER_H

#include <QWidget>
#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QStringList>
#include <QTimer>
#include <QUrl>
#include <QDebug>

#include <stdio.h>

class MyDownloadManager : public QObject
{
    Q_OBJECT
    QNetworkRequest *request;
    QNetworkAccessManager *manager;
    QUrl newurl;
    qint64 bytesDownloadedAtPause;
    bool b_Request;
    QFile *m_file;
public:
    explicit MyDownloadManager(QObject* parent = 0);
    void startDownload(QUrl &url);
    void startRequest(QNetworkRequest *req);

private slots:    
    void PauseDownload();
    void ResumeDownload();
    void WriteFile();
    
public:
    QNetworkReply *reply;
    QString saveFileName(QUrl &url);
    bool saveToDisk(QString &filename, QIODevice *data);

public slots:
    void downloadFinished();
    void cancelDownload();
};

#endif // MYDOWNLOADMANAGER_H
