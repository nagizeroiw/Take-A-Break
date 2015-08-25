#include "qttest.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap* pm = new QPixmap(32, 32);
    // pm->fill(QColor(200, 200, 100));

    QIcon* icon = new QIcon(":/qttest/Resources/copy.png");

    MyTray* tray = new MyTray();

    tray->setIcon(*icon);

    // qDebug(QDir::currentPath().toStdString().c_str());

    tray->start();
    // tray->timeoutMessage();

    return a.exec();
}
