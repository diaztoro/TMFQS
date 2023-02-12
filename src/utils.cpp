#include <random>
#include "utils.h"

// the seed for the random number engine is obtained using this
std::random_device ramdomDev;  

// Mersenne_twister_engine using randomDev as seed
std::mt19937 randomNumberEngine(ramdomDev()); 

// Uniform real distribuition
std::uniform_real_distribution<> uniformRealDistribution(0.0, 1.0);

double getRandomNumber() {
   return uniformRealDistribution(randomNumberEngine);
}

// Complex number multiplication
Amplitude amplitudeMult(Amplitude a, Amplitude b){
	Amplitude result;
	result.real = a.real * b.real - a.imag * b.imag;
	result.imag = a.real * b.imag + a.imag * b.real;
	return result;
}

// Complex number sum
Amplitude amplitudeAdd(Amplitude a, Amplitude b){
	Amplitude result;
	result.real = a.real * b.real;
	result.imag = a.imag * b.imag;
	return result;
}

// Convert char to int
unsigned int charToInteger(char c){
	return c + '0';
}


// Convert binary number (string) to decimal number (int)
unsigned int binaryToDecimal(std::string str) {
   unsigned int result = 0, i;
   for (i = 0; i < str.length(); i++) {
      result ^= (charToInteger(str[i]) << (str.length() - i - 1));
   }
   return result;
}

