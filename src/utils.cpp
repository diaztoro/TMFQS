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

