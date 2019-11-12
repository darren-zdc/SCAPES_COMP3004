#include "Create.h"

// create with path
Create::Create(string dir){
  string path = dir;

  string name = "untitled"; // default name
  int counter = 1; // how many untitled there are

  // if theres no "untitled" file
  ifstream exist(path + "/" + name + ".txt");
  if(!exist){
    ofstream newFile(path + "/" + name + ".txt");
    return;
  }

  // if theres an "untitled" + "num"
  while(true){
    ifstream exist2(path + "/" + name + to_string(counter) + ".txt");
    if(!exist2){
      ofstream newFile(path + "/" + name + to_string(counter) + ".txt");
      break;
    }else{
      counter++;
    }
  }
}
