#include "program.h"

enum flag{ERROR, SUCCESS, CONTINUE};

Program::Program(string filename, string dir) : filename(filename), directory(dir)
{

}

vector<Variable> Program::getVariables()
{
    return variables;
}

int Program::Compile()
{
    string filePath = directory + "/" + filename;
    list<string> lines;
    string line;
    ifstream myprogram(filePath);
    if (myprogram.is_open())
    {
        while(getline(myprogram, line))
        {
            int flag = createStatement(line);
            if (flag == SUCCESS)
            {
                Statement* st = statements.back();
                if(st->compile() == ERROR)
                {
                    return ERROR;
                }
            }
            else if (flag == ERROR)
            {
                return ERROR;
            }
        }
    }
    else if (myprogram.fail())
    {
        //failed to open a file
        return ERROR;
    }

    //Overall check
    for (Label l : labels)
    {
        bool isLabelDeclared = false;
        for (Statement* st : statements)
        {
            if (st->getLabel()->getName() == l.getName())
            {
               isLabelDeclared = true;
               break;
            }
        }
        if (isLabelDeclared == false)
        {
            //Label never declared
            return ERROR;
        }
    }


    //serialization to .cscapes
    this->serializeToJSON();
    return SUCCESS;
}

void Program::Execute()
{


}

int Program::createStatement(string line, string label)
{
    vector<string> lineParses =split(line);

    //Case for empty line
    if (lineParses.size() == 0)
    {
        return CONTINUE;
    }

    if (lineParses[0] == "dci")
    {
        //declares an integer variable
        statements.push_back(new DeclIntStmt(lineParses, label));
    }
    else if (lineParses[0] == "dca")
    {
        //declears an array variable
        statements.push_back(new DeclArrStmt(lineParses, label));
    }
    else if (lineParses[0] == "rdi")
    {
        //reads an integer value from the user
        statements.push_back(new ReadStmt(lineParses, label));

    }
    else if (lineParses[0] == "prt")
    {
        //prints out the value of a variable
        statements.push_back(new PrintStmt(lineParses, label));
    }
    else if (lineParses[0]== "add")
    {
        //add the two values
        statements.push_back(new AddStmt(lineParses, label));
    }
    else if (lineParses[0]== "mov")
    {
        //move varible from sources to another varible
        statements.push_back(new MovStmt(lineParses, label));
    }
    else if (lineParses[0] == "cmp")
    {
        //compares two values to test
        statements.push_back(new CompStmt(lineParses, label));

    }
    else if (lineParses[0]== "jls"){
        //jump to the specified label
        statements.push_back(new JLessStmt(lineParses, label));
    }
    else if (lineParses[0] == "jmr")
    {
        //jump to the specified label
        statements.push_back(new JMoreStmt(lineParses, label));
    }
    else if (lineParses[0]== "jeq"){
        //jump to the specified label
        statements.push_back(new JEqStmt(lineParses, label));
    }
    else if (lineParses[0] == "jmp")
    {
        //unconditional jump to the specified labl
        statements.push_back(new JmpStmt(lineParses, label));
    }
    else if (lineParses[0] == "end")
    {
        //indicates the end of the program
        statements.push_back(new EndStmt(lineParses, label));
        //Deconstruct the statement vector
    }
    else if (lineParses[0] == "#")
    {
        //indicates that the line is a comment
        return CONTINUE;
    }
    else if (lineParses[0].back() == ':')
    {       
        this->createStatement(line.substr(lineParses[0].length()+1, line.length() - lineParses[0].length())
                , lineParses[0].substr(0,lineParses[0].size()-1));
        return SUCCESS;
    }
    else if (lineParses[0] == "\r" || lineParses[0] == "\n" || line == "")
    {
        return CONTINUE;
    }
    else
    {
        //error
        return ERROR;
    }
    statements.back()->setProgram(*this);
    return SUCCESS;
}

int Program::createVariable(string name, int size){
    if(ifExistVariable(name)){
        return 0;
    }
    variables.push_back(Variable(name, size));
    return 1;
}

void Program::createLabel(string name)
{
    if (!ifExistLabel(name))
    {
        labels.push_back(Label(name));
    }
}
void Program::serializeToJSON()
{
    QJsonObject jProgram;
    jProgram["filename"] = QString::fromStdString(this->filename);

    //serialize the statement vector
    QJsonArray jStatements;
    for (Statement* st :statements)
    {
        QJsonObject jStatement;
        jStatement["instruction"] = QString::fromStdString(st->getInstruction());
        QJsonArray jOperands;
        for (Operand op: st->getOperands())
        {
            QJsonObject jOperand;
            jOperand["name"] = QString::fromStdString(op.getValue());
            jOperands.push_back(jOperand);
        }
        if (jOperands.size() != 0)
        {
            jStatement["operands"] = jOperands;
        }
        if (st->getLabel()->getName() != "")
        {
            jStatement["label"] = QString::fromStdString(st->getLabel()->getName());
        }
        jStatements.push_back(jStatement);
    }
    jProgram["statements"] =jStatements;

    //serialize the variable vector
    QJsonArray jVariables;
    for(Variable var:variables)
    {
        QJsonObject jVariable;
        jVariable["name"] = QString::fromStdString(var.getName());
        jVariables.push_back(jVariable);
    }
    jProgram["variables"] = jVariables;

    //serialize the label vector
    QJsonArray jLabels;
    for(Label l:labels)
    {
        QJsonObject jLabel;
        jLabel["name"] = QString::fromStdString(l.getName());
        jLabels.push_back(jLabel);
    }
    jProgram["labels"] = jLabels;

    QJsonDocument doc(jProgram);
    string jsonFilename;
    jsonFilename = directory + "/" + getFileName("/" + this->filename, false) + ".json";
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
    int extensionLength;
    extensionLength = filePath.size() - dotPos +1;
    if(sepPos != string::npos)
    {
        return filePath.substr(sepPos + 1, filePath.size() - (withExtension ? 1 : extensionLength) );
    }
    return "";
}

Variable* Program::findVariable(string name)
{
    for(Variable element: variables)
    {
        if (element.getName() == name)
            return &element;
    }
    return nullptr;
}

int Program::ifExistVariable(string name)
{
    for(Variable element: variables)
    {
        if (element.getName() == name)
            return 1;
    }
    return 0;
}

int Program::ifExistLabel(string name)
{
    for(Label element: labels)
    {
        if (element.getName() == name)
            return 1;
    }
    return 0;
}

int Program::ifPrevCompExist()
{
    if(statements.rbegin()[1]->getInstruction() == "cmp")
    {
        return 1;
    }
    return 0;
}

bool Program::isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

// arrayToInt(): takes a operand and check if its an array and return its index value
int Program::arrayToInt(const std::string& s){
    size_t posOfPlus = s.find("+"); // posistion of the "+" symbol in the operand
    string varName = s.substr(1,posOfPlus-1);
    int index;

    if(s.substr(0,1) != "$"){
        // doesn't strart with $
        return -1;
    }

    if(!ifExistVariable(varName)){
        // variable doesn't exist
        return -1;
    }else{
        if(!findVariable(varName)->isVarArray()){
            //variable exist but is not an array variable
            return -1;
        }
    }

    if(!isNumber(s.substr(posOfPlus+1))){
        // whatever after the "+" sign is not an integer
        return -1;
    }else{
        index = std::stoi(s.substr(posOfPlus+1));
    }
    
    if((!findVariable(varName)->getSize()) <= 0 || (!findVariable(varName)->getSize()) > index){
        // index out of bound
        return -1;
    }
    
    // return the value
    return findVariable(varName)->getValueByIndex(index);

}
