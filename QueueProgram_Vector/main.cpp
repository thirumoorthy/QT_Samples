#include <QtCore/QCoreApplication>
#include "vector.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Vector objVector;
    int choice, value ;

    do
    {
        qDebug("The Queue Implementation using Vector");
        qDebug("1. Add a New Element");
        qDebug("2. Display the Vector");
        qDebug("3. Remove the first element inserted");
        qDebug("4. Exit");
        std::cin>>choice;
        switch(choice)
        {
        case 1:
            qDebug("Enter a new value to be added in the Vector");
            std::cin>>value;
            objVector.addElement(value);
            break;
        case 2:
            objVector.displayVector();
            break;
        case 3:
            objVector.removeElement();
            break;
        default:
            qDebug("Enter a valid choice");
        }
    } while(choice != 4);
    
    return a.exec();
}
