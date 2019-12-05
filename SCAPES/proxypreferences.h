#ifndef PROXYPREFERENCES_H
#define PROXYPREFERENCES_H
#include <preferences.h>
#include <realpreferences.h>
#include <string.h>

class proxypreferences: public Preferences
{
public:
    proxypreferences();
    void setLanguage(string lang, string user);
    int setDirectory(string dir, string user);
    string getDirectory();
    string getLanguage();
private:
    bool checkAccess(string user);
    realpreferences *real = new realpreferences();
};

#endif // PROXYPREFERENCES_H
