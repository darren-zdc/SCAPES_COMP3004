#ifndef PROGRAM_H
#define PROGRAM_H
#include "identifier.h"
#include "preferences.h"
#include "statement.h"
#include "declintstmt.h"
#include "endstmt.h"
#include "identifier.h"
#include "jmorestmt.h"
#include "jmpstmt.h"
#include "printstmt.h"
#include "readstmt.h"
#include "compstmt.h"
#include "variable.h"
#include "label.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;
class Program
{
public:
    Program(string filename);    
    void Compile();
    void Execute();
    void print();
    static string getFileName(string filePath, bool withExtension = true, char seperator = '/');
    vector<Variable> getVariables();
    int createVariable(string name);
    void createLabel(string name);
    Variable* findVariable(Variable var);
    int ifExistVariable(string name);
    int ifExistLabel(string name);
    int ifPrevCompExist();
private:
    vector<Label> labels;
    vector<Statement*> statements;
    vector<Variable> variables;
    Preferences preference;
    string filename;
    string comparisonFlag;
    void createStatement(string line, string label="");
    //void createIdentifier(Statement* st, string line);
    static vector<string> split(string line);
    void serializeToJSON();


};
#endif // PROGRAM_H
