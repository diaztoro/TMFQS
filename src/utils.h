#ifndef UTIL_INCLUDE
#define UTIL_INCLUDE

#include <iostream>
#include "types.h"

// Returns a double between 0.0 and 1.0.
double getRandomNumber(); 
Amplitude amplitudeAdd(Amplitude a, Amplitude b);
Amplitude amplitudeMult(Amplitude a, Amplitude b);
unsigned int binaryToDecimal(std::string str);

#endif
