#include "browser.h"

Browser::Browser(QObject *parent) :
    QObject(parent)
{
    myObject = QString("MyObject") + QString::number(m_iCount++,10);
    setObjectName(myObject);
}

int Browser::m_iCount = 1;

void Browser::sampleFunction(QVariant a)
{
    qDebug()<<"Inside Sample Function"<<a;
    startTimer(1000);
}

void Browser::timerEvent(QTimerEvent *evt)
{
    int timerId = evt->timerId();
    qDebug()<<"Inside Timer Event "<<timerId;
    emit this->Success(timerId);
    this->killTimer(timerId);
}
