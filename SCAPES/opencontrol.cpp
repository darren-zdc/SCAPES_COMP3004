#include "opencontrol.h"
#include <QStringList>
#include <QDirIterator>
#include <QTextStream>

openControl::openControl(QString name, int tag)
{
    this->flag = tag;
    this->name = name;
}

QStringList openControl::openControlFuncitonality()
{
    if (flag == 1) //flag is one, we want to open the specified file
    {
        QStringList contents;
        QDirIterator iterator("../SCAPES/programs/", QDirIterator::Subdirectories);

        while (iterator.hasNext())
        {
            QFile file(iterator.next());
            if (file.fileName() == this->name)
            {
                file.open(QIODevice::ReadOnly);
                QString content = file.readAll();
                contents = content.split(QRegExp("[\n]"), QString::SkipEmptyParts);
            }
        }
        return contents;
    }
    else //flag is 2, we wnt the list of programs
    {
        QStringList filenames;
        QDirIterator iterator("../SCAPES/programs/", QDirIterator::Subdirectories);

        while (iterator.hasNext())
        {
            QFile file(iterator.next());
            file.open(QIODevice::ReadOnly);
            if (file.fileName() != "../SCAPES/programs/.." && file.fileName() != "../SCAPES/programs/.")
            {
                filenames.append(file.fileName());
            }
        }

        return filenames;
    }
}
