#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <QTextEdit>
#include "helperfunction.h"
using namespace std;

class Logger
{
public:
    Logger();
    Logger(QTextEdit*);
    ~Logger();
    static Logger* getInstance();
    void setOutput(QTextEdit* textBox);
    void info(string meg);
    void error(string mes);
    void warning(string mes);
    void debug(string mes);
private:
    QTextEdit* textBox;
    static Logger* myLogger;

};
#endif // LOGGER_H
