#include "preferencemanager.h"

preferenceManager::preferenceManager()
{

}

string preferenceManager::GetLang()
{
    return pref->getLanguage();
}

string preferenceManager::GetDirectory()
{
    return pref->getDirectory();
}

void preferenceManager::SetLang(string lang, string user)
{
    pref->setLanguage(lang, user);
}

void preferenceManager::SetDirectory(string directory, string user)
{
    pref->setDirectory(directory, user);
}
