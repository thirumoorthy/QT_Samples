#include "sender.h"
#include <QTimerEvent>
#include "uthread.h"
#include <QDebug>

Sender::Sender(QObject *parent) :
    QObject(parent)
{
    val = 10 ;
    startTimer(200);
    /*UThread *objUThread = new UThread();
    objUThread->start();

    connect(this,SIGNAL(valueChanged()),objUThread,SLOT(onIncomingEvent()),Qt::DirectConnection);*/
}

void Sender::changeTheValue(int newval)
{
    if(val == newval)
        return;
    qDebug("The Current value : %d",val);
    val = newval;
    emit valueChanged();
}

void Sender::timerEvent(QTimerEvent *evt)
{
    static int timerCount;
    timerCount++ ;
    int id = evt->timerId();
    qDebug("The timer Id is %d",id);
    if(timerCount == 3)
    {
        qDebug() << "Sender File ThreadID =" << QThread::currentThreadId();
        emit valueChanged();
        timerCount = 0 ;
    }
}
