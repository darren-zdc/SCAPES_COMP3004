#ifndef PROGRAM_H
#define PROGRAM_H
#include "identifier.h"
#include "preferences.h"
#include <string>
#include <unordered_set>
using namespace std;
class Program
{
public:
    Program(string filename);    
protected:
    void Compile();
    void Execute();
    void print();
private:
    unordered_set<Identifier> identifiers;
    Preferences preference;
    string filename;
    string comparisonFlag;
};
#endif // PROGRAM_H
