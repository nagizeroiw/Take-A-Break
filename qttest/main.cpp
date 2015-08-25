
#include <QtWidgets/QApplication>
#include "TakeABreak.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    TAB* tab = new TAB();
    tab->start();

    return a.exec();
}
