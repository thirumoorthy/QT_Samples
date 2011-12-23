#include <QtCore/QCoreApplication>
#include <sender.h>
#include <receiver.h>

#include "uthread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    Sender objSender;
    Receiver objReceiver;
    UThread objUThread ; //= new UThread();
    objUThread.start();
    QObject::connect(&objSender,SIGNAL(valueChanged()),&objReceiver,SLOT(onValueChanged()),Qt::QueuedConnection);
    QObject::connect(&objSender,SIGNAL(valueChanged()),&objUThread,SLOT(onIncomingEvent()),Qt::QueuedConnection);
    //objSender.changeTheValue(20);
    return a.exec();
}
