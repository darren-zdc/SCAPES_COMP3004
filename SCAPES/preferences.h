#ifndef PREFERENCES_H
#define PREFERENCES_H
#include <string>
using namespace std;

class Preferences
{
public:
    Preferences();
    void setDirectory(string dir, string user);
    string getDirectory();
    void setLanguage(string lang, string user);
    string getLanguage();

private:
    string directory;
    string language;
};

#endif // PREFERENCES_H
