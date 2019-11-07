#ifndef PROGRAM_H
#define PROGRAM_H
#include <string>
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

    string filename;
    string comparisonFlag;
};
#endif // PROGRAM_H
