#include "preferences.h"

Preferences::Preferences()
{
    this->language = "SCAPES";
    this->directory = "../localRepo";
}

string Preferences::getLanguage()
{
    return this->language;
}

string Preferences::getDirectory()
{
    return this->directory;
}

void Preferences::setLanguage(string lang, string user)
{
    this->language = lang;
}

void Preferences::setDirectory(string dir, string user)
{
    this->directory = dir;
}
