#ifndef BROWSER_H
#define BROWSER_H

#include <QObject>
#include <QVariantMap>
#include <QTimerEvent>
#include <QDebug>

class Browser : public QObject
{
    Q_OBJECT
    static int m_iCount;
    QString myObject;
public:
    explicit Browser(QObject *parent = 0);
protected:
    void timerEvent(QTimerEvent *);
    
signals:
    void Success(QVariant);
    void Failure();
    
public slots:
    void sampleFunction(QVariant a);
    
};

#endif // BROWSER_H
