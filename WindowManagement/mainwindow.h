#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QGraphicsScene>
#include <QMap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QGraphicsScene *myGraphicsscene;
    QGraphicsWebView *myGraphicsWebView;
    QGraphicsWebView *myGraphicsCurrentWebView;
    QString str;
    static int count;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    QMap<QString, QGraphicsWebView *> objMap;
    
private slots:
    void on_LaunchURLpushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
