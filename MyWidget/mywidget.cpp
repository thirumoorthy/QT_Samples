#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    closebutton = new QPushButton(this);
    closebutton->setText("close");
    closebutton->setGeometry(300,100,60,25);
    closebutton->show();
}
