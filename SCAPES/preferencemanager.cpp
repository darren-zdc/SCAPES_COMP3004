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

int preferenceManager::SetDirectory(string directory, string user)
{
    return pref->setDirectory(directory, user);
}
