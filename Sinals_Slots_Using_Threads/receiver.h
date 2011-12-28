#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QDebug>
#include <QThread>

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = 0);
    
signals:
    
public slots:
    void onValueChanged();
};

#endif // RECEIVER_H
