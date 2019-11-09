#include "preferences.h"

Preferences::Preferences()
{
    this->language = "SCAPES";
    this->directory = "../SCAPES/programs/";
}

string Preferences::getLanguage()
{
    return this->language;
}

string Preferences::getDirectory()
{
    return this->directory;
}

void Preferences::setLanguage(string lang)
{
    this->language = lang;
}

void Preferences::setDirectory(string dir)
{
    this->directory = dir;
}
