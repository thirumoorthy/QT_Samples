#include "receiver.h"
#include <QDebug>
#include "uthread.h"

Receiver::Receiver(QObject *parent) :
    QObject(parent)
{
}

void Receiver::onValueChanged()
{
    static int count;
    count++;
    qDebug() << " Timeout Count = " << count;
    qDebug() << "Receiver File ThreadID =" << QThread::currentThreadId();
}
