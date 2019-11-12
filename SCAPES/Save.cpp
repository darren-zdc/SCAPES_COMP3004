#include "Save.h"

Save::Save(string name, vector<string> &instruction, string dir){

  string path = dir;

  ifstream exist(path + "/" + name);
  if(!exist){
    ofstream newFile(path + "/" + name);
  }

  ofstream saveFile;
  saveFile.open(path + "/" + name);

  for(int i=0; i<instruction.size(); i++){
    saveFile << instruction[i] + "\n";
  }

  saveFile.close();


}
