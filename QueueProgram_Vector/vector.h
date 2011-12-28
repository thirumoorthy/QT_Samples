#ifndef VECTOR_H
#define VECTOR_H

#include <QObject>
#include <QVector>
#include <QDebug>

class Vector : public QObject
{
    Q_OBJECT
    QVector<int> objVector ;
public:
    explicit Vector(QObject *parent = 0);
    
signals:
    
public slots:
    void addElement(int);
    void removeElement();
    void displayVector();
};

#endif // VECTOR_H
