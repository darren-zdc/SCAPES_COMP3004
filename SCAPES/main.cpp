#include "mainwindow.h"
#include <uimanager.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    uimanager *manager = new uimanager;
    MainWindow w;
    w.attachDependancies(manager);
    w.show();
    return a.exec();
}
