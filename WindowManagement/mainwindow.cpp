#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myGraphicsscene = new QGraphicsScene ;
    ui->graphicsView->setScene(myGraphicsscene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::count ;

void MainWindow::on_LaunchURLpushButton_clicked()
{
    str = ui->urlcomboBox->currentText();
    myGraphicsWebView = new QGraphicsWebView ;
    count++;
    myGraphicsWebView->setZValue(count);
    qDebug() << "Zval = " << myGraphicsWebView->zValue();
    QString actualURL = QString("http://")
            +str ;
    myGraphicsWebView->setUrl(actualURL);
    myGraphicsWebView->resize(QSize(ui->graphicsView->width(),ui->graphicsView->height()));

    objMap[actualURL] = myGraphicsWebView ;
    myGraphicsCurrentWebView = myGraphicsWebView ;

    myGraphicsscene->addItem(myGraphicsWebView);
}

void MainWindow::on_pushButton_clicked()
{
    QString requestedURL = QString("http://")
            +ui->urlcomboBox->currentText() ;

    //qDebug()<<"The Requested URL : "<< requestedURL;

    QGraphicsWebView *objGWebView = objMap[requestedURL];

    //qDebug() << "Zval = " << objGWebView->zValue();

    int zVal = objGWebView->zValue();
    int topmostZVal = myGraphicsCurrentWebView->zValue();

    //qDebug() << "Zval = " << myGraphicsCurrentWebView->zValue();

    myGraphicsCurrentWebView->setZValue(zVal);
    objGWebView->setZValue(topmostZVal);
    myGraphicsCurrentWebView = objGWebView ;

    //qDebug() << "Zval = " << objGWebView->zValue();
    //qDebug() << "Zval = " << myGraphicsCurrentWebView->zValue();
}
