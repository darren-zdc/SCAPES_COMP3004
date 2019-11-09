#include "mainwindow.h"
#include <uimanager.h>
#include <QApplication>
#include <Create.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    uimanager *manager = new uimanager;
    MainWindow w;
    w.attachDependancies(manager);
    manager->window = &w;
    w.show();
    return a.exec();
}
