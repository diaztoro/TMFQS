#include <random>
#include "utils.h"

// the seed for the random number engine is obtained using this
std::random_device ramdomDevice;  

// Mersenne_twister_engine using randomDev as seed
std::mt19937 randomNumberEngine(ramdomDevice()); 

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

// Complex number addtion
Amplitude amplitudeAdd(Amplitude a, Amplitude b){
	Amplitude result;
	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return result;
}

// Complex number subtraction
Amplitude amplitudeSubt(Amplitude a, Amplitude b){
	Amplitude result;
	result.real = a.real - b.real;
	result.imag = a.imag - b.imag;
	return result;
}

// Convert char to int
unsigned int charToInteger(char c){
	int i;
	i = int(c) - 48;
	return i;
}


// Convert binary number (string) to decimal number (int)
unsigned int binaryToDecimal(std::string str) {
   unsigned int result = 0, i;
   for (i = 0; i < str.length(); i++) {
      result ^= (charToInteger(str[i]) << (str.length() - i - 1));
   }
   return result;
}

// Copy "numbits" bits from "source" to "destination" to the position "at"
// Example: destination = 8 (1000)
// 			source = 3 (11)
// 			at = 0
// 			numbits = 2
// 			result = 11 (1011)
unsigned int copyBits(int destination, int source, int at, int numbits){
   // int mask = ((1LL<<numbits)-1)<<at; // 1st aproach
   int mask = ((~0u)>>(sizeof(int)*8-numbits))<<at; // 2nd aproach
   return (destination&~mask)|((source<<at)&mask);
}

// e Raised to a complex number
Amplitude eRaisedToComplex(Amplitude amp){
	// e^(b+ic) = (e^b)(e^(ic))
	// e^(ic) = (cos c) + i(sin c)
	// e^(b+ic) = (e^b)((cos c) + i(sin c))
	Amplitude result;
	result.real = pow(e, amp.real) * cos(amp.imag);
	result.imag = pow(e, amp.real) * sin(amp.imag);
	return result;
}


double absoluteValue(Amplitude amp){
	return sqrt(pow(amp.real, 2) + pow(amp.imag, 2));
}
