#include "mywiget.h"
#include "browser.h"

MyWiget::MyWiget(QWidget *parent) :
    QWebView(parent)
{
    QWebFrame *myFrame = this->page()->mainFrame();
    myFrame->addToJavaScriptWindowObject("boschInternal",this);
}

QString MyWiget::sayHello(int data)
{
    //emit sendSignal();

    return QString("Hello ");
}

QString MyWiget::createBrowserObject()
{
    Browser *pBrowserObject = new Browser(this);
    pBrowserObject->setParent(this);

    qDebug()<<"Inside Broser Object Function"<<pBrowserObject->objectName();

    return pBrowserObject->objectName();
}
