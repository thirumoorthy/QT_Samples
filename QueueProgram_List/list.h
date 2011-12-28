#ifndef LIST_H
#define LIST_H

#include <QObject>


class List : public QObject
{
    Q_OBJECT

    QList<int> objElement ;
public:
    explicit List(QObject *parent = 0);
    
signals:
    
public slots:
    void addElement(int);
    void removeElement();
    void displayList();
};

#endif // LIST_H
