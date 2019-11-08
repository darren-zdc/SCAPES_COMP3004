#include "program.h"

Program::Program(string filename) : preference(), filename(filename)
{
}

void Program::Compile()
{
    string filePath = preference.getDirectory() + "/" + filename;
    list<string> lines;
    string line;
    ifstream myprogram(filePath);
    if (myprogram.is_open())
    {
        while(getline(myprogram, line))
        {
            CreateStatement(line);
            Statement* st = statements.back();
            st->compile();
        }
    }

}

void Program::Execute()
{


}

void Program::CreateStatement(string line)
{
    vector<string> lineParses =Split(line);
    if (lineParses[0] == "dci")
    {
        //declares an integer variable
        statements.push_back(new DeclIntStmt(line));
    }
    else if (lineParses[0] == "rdi")
    {
        //reads an integer value from the user
        statements.push_back(new ReadStmt(line));

    }
    else if (lineParses[0] == "prt")
    {
        //prints out the value of a variable
        statements.push_back(new PrintStmt(line));
    }
    else if (lineParses[0] == "cmp")
    {
        //compares two values to test
        statements.push_back(new CompStmt(line));

    }
    else if (lineParses[0] == "jmr")
    {
        //jump to the specified label
        statements.push_back(new JMoreStmt(line));
    }
    else if (lineParses[0] == "jmp")
    {
        //unconditional jump to the specified labl
        statements.push_back(new JmpStmt(line));
    }
    else if (lineParses[0] == "end")
    {
        //indicates the end of the program
        statements.push_back(new EndStmt());

        //Deconstruct the statement vector
    }
    else if (lineParses[0] == "#")
    {
        //indicates that the line is a comment
    }
    else
    {
        //error
    }
}

vector<string> Program::Split(string line)
{
    istringstream iss(line);
    vector<string> results((istream_iterator<std::string>(iss)),
                   istream_iterator<std::string>());
    return results;
}
