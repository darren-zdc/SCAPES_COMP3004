#include "opencontrol.h"
#include <QStringList>
#include <QDirIterator>

openControl::openControl(QString name, int tag)
{
    this->flag = tag;
}

QStringList openControl::openControlFuncitonality()
{
    if (flag == 2)
    {
        QStringList filenames;
        QDirIterator iterator("./programs/", QDirIterator::Subdirectories);
        while (iterator.hasNext())
        {
            QFile file(iterator.next());
            file.open(QIODevice::ReadOnly);
            filenames.append(file.fileName());
        }
        return filenames;
    }
    //QStringList temp;
    //temp << "file" << "file2";
    //return temp;
}
