#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include <QDebug>
#include <QTimerEvent>
#include <QThread>

class Sender : public QObject
{
    Q_OBJECT
    int val;
public:
    explicit Sender(QObject *parent = 0);

protected:
    void timerEvent(QTimerEvent *);
    
signals:
    void valueChanged();
public slots:
};

#endif // SENDER_H
