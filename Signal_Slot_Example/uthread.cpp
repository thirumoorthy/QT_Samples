#include "uthread.h"
#include <QDebug>
#include <QEventLoop>

UThread::UThread(QThread *parent) :
    QThread(parent)
{
    moveToThread(this);
}

void UThread::run()
{
   QEventLoop loop;
   loop.exec();
}

void UThread::onIncomingEvent()
{
    qDebug() << "UThread File ThreadID = " << currentThreadId();
}

