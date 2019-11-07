#ifndef PREFERENCES_H
#define PREFERENCES_H
#include <string>
using namespace std;

class Preferences
{
public:
    Preferences();
    string directory;
    string language;
    void setDirectory(string dir);
    string getDirectory();
    void setLanguage(string lang);
    string getLanguage();
};

#endif // PREFERENCES_H
