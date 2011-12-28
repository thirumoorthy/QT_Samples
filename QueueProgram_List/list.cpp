#include "list.h"
#include <QDebug>
#include <QList>

List::List(QObject *parent) :
    QObject(parent)
{
}

void List::addElement(int newElement)
{
    objElement.append(newElement);

}

void List::removeElement()
{
     objElement.removeFirst();
}

void List::displayList()
{
    int count = objElement.size();
    if(count == 0)
    {
        qDebug()<<"No Elements in the List to Display";
    }
    else
    {
        for(int icount=0; icount < count; icount++)
        {
            qDebug()<<(objElement.value(icount));
        }
    }
}
