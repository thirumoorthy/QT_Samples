#ifndef MYPROGRESSBAR_H
#define MYPROGRESSBAR_H

#include <QWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QDebug>

class MyProgressBar : public QWidget
{
    Q_OBJECT
    QProgressBar *qProgressbar ;
    int progressvalue ;
    static int yPos ;
public:
    explicit MyProgressBar(QWidget *parent = 0);
    QPushButton *cancelPushbutton ;
    QPushButton *pausePushbutton ;
signals:
    void sigPauseDownload();
    void sigResumeDownload();
    
public slots:
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void sendPauseResumeSignal();
    
};

#endif // MYPROGRESSBAR_H
