#ifndef COMPILECONTROL_H
#define COMPILECONTROL_H
#include <QString>
#include <string>
using namespace  std;

class compileControl
{
public:
    compileControl(QString name, string dir);
    int compile();
private:
    QString filename;
    string directory;
};

#endif // COMPILECONTROL_H
