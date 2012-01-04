#ifndef MYWIGET_H
#define MYWIGET_H

#include <QtWebKit>
#include <QDebug>

class MyWiget : public QWebView
{
    Q_OBJECT
public:
    explicit MyWiget(QWidget *parent = 0);
    
signals:
    void sendSignal();
    void sigSuccess();
    void sigFailure();
public slots:
    QString sayHello(int );
    QString createBrowserObject();
};

#endif // MYWIGET_H
