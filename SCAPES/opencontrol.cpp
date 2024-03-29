#include "opencontrol.h"
#include <QStringList>
#include <QDirIterator>
#include <QTextStream>

openControl::openControl(QString name, int tag, string dir) //setup working variables
{
    this->flag = tag;
    QString temp = QString::fromStdString(dir);
    this->directory = temp;
    temp.append("/");
    temp.append(name);
    this->name = temp;
}

QStringList openControl::openControlFuncitonality()
{
    if (flag == 1) //flag is one, we want to open the specified file
    {
        QStringList contents;
        QDirIterator iterator(directory, QDirIterator::Subdirectories); //go to working directory
        while (iterator.hasNext())
        {
            QFile file(iterator.next());
            if (file.fileName() == this->name) //search for selected file of valid type
            {
                file.open(QIODevice::ReadOnly);
                QString content = file.readAll();
                contents = content.split(QRegExp("[\n]"), QString::SkipEmptyParts);
                file.close();
            }
        }
        return contents;
    }
    else //flag is 2, we want the list of programs
    {
        QStringList filenames;
        QDirIterator iterator(directory, QDirIterator::Subdirectories);

        while (iterator.hasNext()) //iterate through working directory
        {
            QFile file(iterator.next());
            if (file.fileName().endsWith(".txt") || file.fileName().endsWith(".json")) //return files of valid type only
            {
                file.open(QIODevice::ReadOnly);
                filenames.append(file.fileName());
                file.close();
            }
        }

        return filenames;
    }
}
