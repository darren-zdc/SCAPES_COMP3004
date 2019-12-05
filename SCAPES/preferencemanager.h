#ifndef PREFERENCEMANAGER_H
#define PREFERENCEMANAGER_H

#include <proxypreferences.h>
#include <string>
using namespace std;

class preferenceManager
{
public:
    preferenceManager();
    int SetDirectory(string directory, string user);
    void SetLang(string directory, string user);
    string GetDirectory();
    string GetLang();
private:
    proxypreferences *pref = new proxypreferences;
};

#endif // PREFERENCEMANAGER_H
