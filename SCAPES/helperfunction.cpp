#include "helperfunction.h"

HelperFunction::HelperFunction()
{

}


int HelperFunction::isArraySyntax(string input, string* varname, string* i)
{
    if (input[0] == '$')
    {
        if (!input.find("+"))
            return 0;
        *varname = input.substr(1,input.find("+")-1);
        *i = input.substr(input.find("+"), input.length() - input.find("+"));
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

vector<string> HelperFunction::split(string str)
{   
    vector<string> v;
    string temp;
    for( size_t i=0; i<str.length(); i++){
        char c = str[i];
        //temp += to_string(c);
        if( c == ' ' )
        {
            v.push_back(temp);
            temp = "";
        }
        else if (c == '\"' )
        {
            temp += string(1,c);
            i++;
            while( str[i] != '\"' )
            {
                temp += string(1, str[i]);
                i++;
            }
            temp += string(1, str[i]);
        }
        else {

            temp += string(1, str[i]);

        }
    }
    v.push_back(temp);
    return v;
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
