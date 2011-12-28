#include "sender.h"

Sender::Sender(QObject *parent) :
    QObject(parent)
{
    val = 10 ;
    startTimer(200);
}

void Sender::timerEvent(QTimerEvent *evt)
{
    static int timerCount;
    timerCount++ ;
    if(timerCount == 3)
    {
        qDebug() << "Sender File ThreadID =" << QThread::currentThreadId();
        emit valueChanged();
        timerCount = 0 ;
    }

}
