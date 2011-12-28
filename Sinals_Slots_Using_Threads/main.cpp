#include <QtCore/QCoreApplication>
#include "sender.h"
#include "receiver.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    Sender *objSender = new Sender;
    Receiver *objReceiver = new Receiver;

    QObject::connect(objSender,SIGNAL(valueChanged()),objReceiver,SLOT(onValueChanged()),Qt::QueuedConnection);

    QThread *objThread = new QThread;
    objSender->moveToThread(objThread);
    objThread->start();

    return a.exec();
}
