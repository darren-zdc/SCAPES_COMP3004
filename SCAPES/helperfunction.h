#ifndef HELPERFUNCTION_H
#define HELPERFUNCTION_H

#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

class HelperFunction
{
public:
    HelperFunction();
    static int isArraySyntax(string input);
    static int isNumber(const std::string& s);
    static string getFileName(string filePath, bool withExtension = true, char seperator = '/');
    static vector<string> split(string line);
    static string getCurrentTime();



};

#endif // HELPERFUNCTION_H
