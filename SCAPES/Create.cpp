#include "Create.h"

// default path
Create::Create(){
  Create("../programs/");
}

// create with path
Create::Create(string p){
  string path = p;

  string name = "untitled"; // default name
  int counter = 1; // how many untitled there are

  // if theres no "untitled" file
  ifstream exist(path + name);
  if(!exist){
    ofstream newFile(path + name);
    return;
  }

  // if theres an "untitled" + "num"
  while(true){
    ifstream exist2(path + name + to_string(counter));
    if(!exist2){
      ofstream newFile(path + name + to_string(counter));
      break;
    }else{
      counter++;
    }
  }
}
