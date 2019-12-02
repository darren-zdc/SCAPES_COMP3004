#ifndef PROGRAM_H
#define PROGRAM_H
#include "compstmt.h"
#include "declintstmt.h"
#include "endstmt.h"
#include "identifier.h"
#include "jmorestmt.h"
#include "jmpstmt.h"
#include "printstmt.h"
#include "readstmt.h"
#include "statement.h"
#include "variable.h"
#include "declarrstmt.h"
#include "addstmt.h"
#include "movstmt.h"
#include "jlessstmt.h"
#include "jeqstmt.h"
#include "label.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;
enum flag{ERROR, SUCCESS, CONTINUE};

class Program
{

public:
    Program(string filename, string dir);
    int Compile();
    int Execute();
    void print();
    static string getFileName(string filePath, bool withExtension = true, char seperator = '/');
    static Program* deserializeToObject(string filename, string dir);

    vector<Variable> getVariables();
    int createVariable(string name);
    int createVariable(string name, int size);
    void createLabel(string name);
    int createStatement(string instr, vector<string> operds, string label="");
    Variable* findVariable(string name);
    int ifExistVariable(string name, Variable* output);
    int ifExistLabel(string name);
    int ifPrevCompExist();

    int readInput();
    int output(string value);
    int setVariable(string name, int value, int index);
    int setVariable(string name, int value);
    bool isNumber(const std::string& s);
    int arrayToInt(const std::string& s);
private:
    vector<Label> labels;
    vector<Statement*> statements;
    vector<Variable> variables;
    string filename;
    string directory;
    string comparisonFlag;
    int createStatement(string line, string label="");
    //void createIdentifier(Statement* st, string line);
    static vector<string> split(string line);
    void serializeToJSON();
};
#endif // PROGRAM_H
