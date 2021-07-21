#include "gotoxy.hpp"
#include <iostream>

//Macro for control position
#define gotoxy(x,y) (cout <<"\033["<< y <<';'<< x <<'H')

using namespace std;

