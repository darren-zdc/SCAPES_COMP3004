#include "helperfunction.h"

HelperFunction::HelperFunction()
{

}


int HelperFunction::isArraySyntax(string input, string* varname, int* i)
{
    if (input[0] == '$')
    {
        if (!input.find("+"))
            return 0;
        *varname = input.substr(1,input.find("+")-1);
        int index = stoi(input.substr(input.find("+"), input.length() - input.find("+")));
        if (index < 0)
        {
            //array index cannot less than 0
            return 0;
        }
        *i = index;
        return 1;
    }
    return 0;
}

int HelperFunction::isNumber(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}


string HelperFunction::getFileName(string filePath, bool withExtension, char seperator)
{
    // Get last dot position
    std::size_t dotPos = filePath.rfind('.');
    std::size_t sepPos = filePath.rfind(seperator);
    int extensionLength;
    extensionLength = filePath.size() - dotPos +1;
    if(sepPos != string::npos)
    {
        return filePath.substr(sepPos + 1, filePath.size() - (withExtension ? 1 : extensionLength) );
    }
    return "";
}

vector<string> HelperFunction::split(string line)
{
    istringstream iss(line);
    vector<string> results((istream_iterator<std::string>(iss)),
                   istream_iterator<std::string>());
    return results;
}

string HelperFunction::getCurrentTime()
{
   string currTime;
   //Current date/time based on current time
   time_t now = time(0);
   // Convert current time to string
   currTime.assign(ctime(&now));

   // Last charactor of currentTime is "\n", so remove it
   string currentTime = currTime.substr(0, currTime.size()-1);
   return "[" + currentTime + "]";
}
