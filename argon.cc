#include "argon.h"
#include <iostream>
using namespace std;



	 
Argon* Argon::clone() const { return new Argon(*this);}