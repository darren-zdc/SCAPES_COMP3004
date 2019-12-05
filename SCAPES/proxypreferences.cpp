#include "proxypreferences.h"

proxypreferences::proxypreferences()
{

}

bool proxypreferences::checkAccess(string user) //core of proxy object, used to check is given user has access to requested functionality
{
    if (user == "systemAdmin")
        return true;
    else
        return false;
}

void proxypreferences::setLanguage(string lang, string user) //overwritten function to check permissions before setting language
{
    if (checkAccess(user))
    {
        real->setLanguage(lang, user); //communicate with real preference object is user has valid permissions
    }
}

int proxypreferences::setDirectory(string dir, string user) //overwritten function to check permissions before setting directory
{
    if (checkAccess(user))
    {
        real->setDirectory(dir, user); //communicate with real preference object is user has valid permissions
        return 1;
    }
    return 0;
}

string proxypreferences::getDirectory() //permission check not required to get the current directory
{
    return real->getDirectory();
}

string proxypreferences::getLanguage() //premission check not required to get the current language
{
    return real->getLanguage();
}
