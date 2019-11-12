#include <iostream>
#include <QApplication>
#include "mainwindow.h"
#include "uimanager.h"
#include "Create.h"
#include "program.h"
//#include <stdio.h>  /* defines FILENAME_MAX */
//#include <unistd.h>
//#include <QDebug>
//#define GetCurrentDir getcwd

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    uimanager *manager = new uimanager;
    MainWindow w;
    w.attachDependancies(manager);
    manager->window = &w;

    w.show();
    return a.exec();
    /*
     * Get the current working directory
     */
    /*
    char cCurrentPath[FILENAME_MAX];
    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    {
        return errno;
    }
    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';
    printf ("The current working directory is %s", cCurrentPath);
    */

}

