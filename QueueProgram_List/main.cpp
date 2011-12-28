#include <QtCore/QCoreApplication>
#include "list.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    List objList;
    int choice, value ;

    do
    {
        qDebug("The Queue Implementation using List");
        qDebug("1. Add a New Element");
        qDebug("2. Display the List");
        qDebug("3. Remove the first element inserted");
        qDebug("4. Exit");
        std::cin>>choice;
        switch(choice)
        {
        case 1:
            qDebug("Enter a new value to be added in the List");
            std::cin>>value;
            objList.addElement(value);
            break;
        case 2:
            objList.displayList();
            break;
        case 3:
            objList.removeElement();
            break;
        default:
            qDebug("Enter a valid choice");
        }
    } while(choice != 4);

    return a.exec();
}
