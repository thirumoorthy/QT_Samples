#include "myprogressbar.h"

MyProgressBar::MyProgressBar(QWidget *parent) :
    QWidget(parent)
{
    progressvalue = 0;

    qProgressbar = new QProgressBar(parent);
    qProgressbar->setValue(0);
    yPos += 30 ;
    qProgressbar->setGeometry(QRect(80,yPos,200,25));
    qProgressbar->setValue(0);
    qProgressbar->show();

    pausePushbutton = new QPushButton(parent);
    pausePushbutton->setText("Pause");
    pausePushbutton->setGeometry(300,yPos,60,25);
    pausePushbutton->show();

    cancelPushbutton = new QPushButton(parent);
    cancelPushbutton->setText("Cancel");
    cancelPushbutton->setGeometry(365,yPos,60,25);
    cancelPushbutton->show();
}

int MyProgressBar :: yPos = 120;

void MyProgressBar::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    progressvalue = (bytesReceived * 100) / bytesTotal;
    qProgressbar->setValue(progressvalue);
}

void MyProgressBar::sendPauseResumeSignal()
{
    if(pausePushbutton->text() == "Pause")
    {
        pausePushbutton->setText("Resume");
        emit sigPauseDownload();
        qDebug()<<"Pause Button Pressed ";
    }
    else
    {
        pausePushbutton->setText("Pause");
        emit sigResumeDownload();
        qDebug()<<"Resume Button Pressed ";
    }
}
