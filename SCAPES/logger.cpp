#include "logger.h"
#include <filemanager.h>
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

void Logger::setManager(filemanager *manager)
{
    this->manager = manager;
}

void Logger::info(string meg)
{
    this->manager->sendMessage("[INFO]: " + HelperFunction::getCurrentTime() + " " + meg, "Logger");
}

void Logger::error(string meg)
{
    this->manager->sendMessage("[ERROR]: " + HelperFunction::getCurrentTime() + " " + meg, "Logger");
}


void Logger::warning(string meg)
{
    this->manager->sendMessage("[WARNING]: " + HelperFunction::getCurrentTime() + " " + meg, "Logger");
}


void Logger::debug(string meg)
{
    this->manager->sendMessage("[DEBUG]: " + HelperFunction::getCurrentTime() + " " + meg, "Logger");
}

