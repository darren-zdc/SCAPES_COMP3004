#ifndef COMPILECONTROL_H
#define COMPILECONTROL_H
#include <QString>

class compileControl
{
public:
    compileControl(QString name);
    void compile();
private:
    QString filename;
};

#endif // COMPILECONTROL_H
