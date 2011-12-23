#ifndef SENDER_H
#define SENDER_H

#include <QObject>
//#include "uthread.h"

class Sender : public QObject
{
    Q_OBJECT
    int val;
    //UThread *objUThread;
public:
    explicit Sender(QObject *parent = 0);

protected:
    void timerEvent(QTimerEvent *);
    
signals:
    void valueChanged();
    
public slots:
    void changeTheValue(int );
};

#endif // SENDER_H
