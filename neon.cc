#include "neon.h"
#include <iostream>
#include <string>
using namespace std;





Neon* Neon::clone() const { return new Neon(*this);}