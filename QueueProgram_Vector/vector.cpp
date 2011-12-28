#include "vector.h"


Vector::Vector(QObject *parent) :
    QObject(parent)
{
}

void Vector::addElement(int newElement)
{
    objVector.append(newElement);
}

void Vector::removeElement()
{
    objVector.remove(0);
}

void Vector::displayVector()
{
    int count = objVector.size();
    if(count == 0)
    {
        qDebug()<<"No Elements in the Vector to Display";
    }
    else
    {
        for(int icount=0; icount < count; icount++)
        {
            qDebug()<<(objVector.value(icount));
        }
    }
}
