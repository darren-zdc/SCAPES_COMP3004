#include "program.h"

Program::Program(string filename) : preference(), filename(filename)
{
}

vector<Variable> Program::getVariables()
{
    return variables;
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
            createStatement(line);
            Statement* st = statements.back();
            st->compile();
            createIdentifier(st, line);
        }
    }
    else if (myprogram.fail())
    {
        //failed to open a file
        string v;
    }


    //serialization to .cscapes
    this->serializeToJSON();
}

void Program::Execute()
{


}

void Program::createStatement(string line)
{
    vector<string> lineParses =split(line);
    if (lineParses[0] == "dci")
    {
        //declares an integer variable
        statements.push_back(new DeclIntStmt(lineParses));
        statements.back()->setProgram(*this);
    }
    else if (lineParses[0] == "rdi")
    {
        //reads an integer value from the user
        statements.push_back(new ReadStmt(lineParses));

    }
    else if (lineParses[0] == "prt")
    {
        //prints out the value of a variable
        statements.push_back(new PrintStmt(lineParses));
    }
    else if (lineParses[0] == "cmp")
    {
        //compares two values to test
        statements.push_back(new CompStmt(lineParses));

    }
    else if (lineParses[0] == "jmr")
    {
        //jump to the specified label
        statements.push_back(new JMoreStmt(lineParses));
    }
    else if (lineParses[0] == "jmp")
    {
        //unconditional jump to the specified labl
        statements.push_back(new JmpStmt(lineParses));
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

void Program::createIdentifier(Statement* st, string line)
{
    vector<string> lineParses =split(line);
    if (lineParses[0] == "dci")
    {
        //declares an integer variable
        variables.push_back(Variable(lineParses[1]));
    }
    else if (lineParses[0] == "rdi")
    {
        //reads an integer value from the user
        //maybe do nothing, the variable get assigned at the runtime. By default, the value is 0.

    }
    else if (lineParses[0] == "prt")
    {
        //prints out the value of a variable
    }
    else if (lineParses[0] == "cmp")
    {
        //compares two values to test

    }
    else if (lineParses[0] == "jmr")
    {
        //jump to the specified label

    }
    else if (lineParses[0] == "jmp")
    {
        //unconditional jump to the specified labl

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

void Program::serializeToJSON()
{
    QJsonObject jProgram;
    jProgram["filename"] = QString::fromStdString(this->filename);
    QJsonArray jStatements;
    for(Statement* st :statements)
    {
        QJsonObject jStatement;
        jStatement["instruction"] = QString::fromStdString(st->getInstruction());
        QJsonArray jOperands;
        for(Operand op: st->getOperands())
        {
            QJsonObject jOperand;
            jOperand["name"] = QString::fromStdString(op.getValue());
            jOperands.push_back(jOperand);
        }
        jStatement["operands"] = jOperands;
        jStatements.push_back(jStatement);
    }
    jProgram["statements"] =jStatements;
    QJsonDocument doc(jProgram);
    string jsonFilename;
    jsonFilename = preference.getDirectory() + getFileName("/" + this->filename, false) + ".json";
    QFile jsonFile(QString::fromStdString(jsonFilename));
    jsonFile.open(QIODevice::WriteOnly);
    jsonFile.write(doc.toJson());

}

vector<string> Program::split(string line)
{
    istringstream iss(line);
    vector<string> results((istream_iterator<std::string>(iss)),
                   istream_iterator<std::string>());
    return results;
}


string Program::getFileName(string filePath, bool withExtension, char seperator)
{
    // Get last dot position
    std::size_t dotPos = filePath.rfind('.');
    std::size_t sepPos = filePath.rfind(seperator);

    if(sepPos != string::npos)
    {
        return filePath.substr(sepPos + 1, filePath.size() - (withExtension || dotPos == string::npos ? 1 : dotPos) );
    }
    return "";
}
