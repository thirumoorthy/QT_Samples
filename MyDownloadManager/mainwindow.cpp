#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydownloadmanager.h"
#include "myprogressbar.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_download1_pushButton_clicked()
{
    this->execute();
}

void MainWindow::doDownload(QUrl &url)
{
    qDebug()<<"Inside the doDownload function . . . , ";
    MyDownloadManager *downloadMgr = new MyDownloadManager();
    MyProgressBar *myProgressbar = new MyProgressBar(this);

    downloadMgr->startDownload(url);
    connect(downloadMgr->reply, SIGNAL(downloadProgress(qint64,qint64)),myProgressbar, SLOT(downloadProgress(qint64,qint64)));
    connect(myProgressbar->cancelPushbutton, SIGNAL(clicked()),downloadMgr, SLOT(cancelDownload()));
    connect(myProgressbar->pausePushbutton, SIGNAL(clicked()),myProgressbar, SLOT(sendPauseResumeSignal()));
    connect(myProgressbar, SIGNAL(sigPauseDownload()),downloadMgr, SLOT(PauseDownload()));
    connect(myProgressbar, SIGNAL(sigResumeDownload()),downloadMgr, SLOT(ResumeDownload()));
}

void MainWindow::execute()
{
    QString strURL = ui->download1_lineEdit->text();
    if(strURL.isEmpty())
    {
        qDebug()<<" The download address is empty . . . , ";
        return;
    }
    QUrl url = QUrl::fromEncoded(strURL.toLocal8Bit());
    qDebug()<<"The URL is : "<< url;
    doDownload(url);
}
