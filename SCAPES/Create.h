#ifndef CREATE_H
#define CREATE_H

#include <iostream>
#include <fstream>

#include "preferences.h"

using namespace std;

class Create{

public:
  Create(string dir);

private:
  Preferences pref;
};

#endif // CREATE_H
