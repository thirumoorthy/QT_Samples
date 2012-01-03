#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QStringList>
#include <QTimer>
#include <QUrl>
#include <QDebug>
#include <QWidget>
#include <QProgressBar>

#include <stdio.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT            
public:
    explicit MainWindow(QWidget *parent = 0);
    QProgressBar *qProgressbar ;
    void doDownload(QUrl &url);    

    ~MainWindow();
    
private slots:
    void on_download1_pushButton_clicked();

public slots:
    void execute();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
