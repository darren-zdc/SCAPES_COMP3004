#include "test.h"
#include <iostream>

#include "Create.h"
#include "Save.h"
#include <vector>

using namespace std;

int main(){


  // create a program
  vector<string> inst;
  inst.push_back("test1");
  inst.push_back("test2");
  inst.push_back("test3");
  inst.push_back("test4");
  inst.push_back("test5");
  Save{"Pgm1", inst, "../programs/"};
  //Create createWithPath("../testPath/");
}
