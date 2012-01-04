#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    static int count;
    int windowNumber;
public:
    QMap<int, QWidget*> mapObject;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void on_newWindow_pushButton_clicked();

    void on_zOrder_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
