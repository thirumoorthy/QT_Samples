#ifndef UTHREAD_H
#define UTHREAD_H

#include <QThread>

class UThread : public QThread
{
    Q_OBJECT
public:
    explicit UThread(QThread *parent = 0);
protected:
    void run();
signals:

public slots:
    void onIncomingEvent();
};
#endif // UTHREAD_H
