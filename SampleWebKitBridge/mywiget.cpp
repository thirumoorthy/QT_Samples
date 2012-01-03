#include "mywiget.h"

MyWiget::MyWiget(QWidget *parent) :
    QWebView(parent)
{
    QWebFrame *myFrame = this->page()->mainFrame();
    myFrame->addToJavaScriptWindowObject("boschInternal",this);
}

QString MyWiget::sayHello(int data)
{
    emit sendSignal();

    return QString("Hello ");
}
