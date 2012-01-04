#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mywidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    windowNumber = 0;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::count = 65;

void MainWindow::on_newWindow_pushButton_clicked()
{
    windowNumber++ ;
    MyWidget *widget = new MyWidget ;
    widget->setWindowTitle(QString("Window - ") + count);
    widget->setGeometry(600,600,400,400);
    mapObject[windowNumber] = widget ;
    count++ ;
    widget->show();
    connect(widget->closebutton,SIGNAL(clicked()),widget,SLOT(close()));
}

void MainWindow::on_zOrder_pushButton_clicked()
{
    int window = ui->zOrder_lineEdit->text().toInt() ;
    if (NULL != mapObject[window])
    {
        mapObject[window]->raise();
    }
}
