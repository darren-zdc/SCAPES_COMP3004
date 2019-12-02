#include "logger.h"
Logger* Logger::myLogger = nullptr;

Logger::Logger()
{

}

Logger::Logger(QTextEdit* textBox) : textBox(textBox)
{}

Logger::~Logger()
{
    delete(myLogger);
}

Logger* Logger::getInstance()
{
    if (myLogger == nullptr)
    {
        myLogger = new Logger();
    }
    return myLogger;
}

void Logger::setOutput(QTextEdit *textBox)
{
    this->textBox = textBox;
}

void Logger::info(string meg)
{
    textBox->append(QString::fromStdString("[INFO]: " + HelperFunction::getCurrentTime() + " " + meg));
}

void Logger::error(string meg)
{
    textBox->append(QString::fromStdString("[ERROR]: " + HelperFunction::getCurrentTime() + " " + meg));
}

void Logger::warning(string meg)
{
    textBox->append(QString::fromStdString("[WARNING]: " + HelperFunction::getCurrentTime() + " " + meg));
}

void Logger::debug(string meg)
{
    textBox->append(QString::fromStdString("[DEBUG]: " + HelperFunction::getCurrentTime() + " " + meg));
}
