#ifndef SAVE_H
#define SAVE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include "preferences.h"

using namespace std;

class Save{

public:
  Save(string name, vector<string> &instruction, string dir);
};

#endif // SAVE_H
