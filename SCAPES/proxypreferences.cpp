#include "proxypreferences.h"

proxypreferences::proxypreferences()
{

}

bool proxypreferences::checkAccess(string user)
{
    if (user == "systemAdmin")
        return true;
    else
        return false;
}

void proxypreferences::setLanguage(string lang, string user)
{
    if (checkAccess(user))
    {
        real->setLanguage(lang, user);
    }
}

void proxypreferences::setDirectory(string dir, string user)
{
    if (checkAccess(user))
    {
        real->setDirectory(dir, user);
    }
}

string proxypreferences::getDirectory()
{
    return real->getDirectory();
}

string proxypreferences::getLanguage()
{
    return real->getLanguage();
}
