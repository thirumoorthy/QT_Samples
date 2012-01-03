#include <QtGui>
#include "mywiget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWiget myObject;
    myObject.load(QUrl("file:///home/thiru/Desktop/test.html"));
    myObject.show();
    return a.exec();
}
