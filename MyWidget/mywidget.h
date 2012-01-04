#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    QPushButton *closebutton ;
    explicit MyWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // MYWIDGET_H
