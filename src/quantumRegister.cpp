#include "quantumRegister.h"
#include <iostream>

// Quantum Register class implementation
//
//Constructors ###################################
quantumRegister::quantumRegister(unsigned int numQubits) {
	this->globalNumQubits = numQubits;
	this->statesVector.push_back(amplitude(1,0)); 
}

//Get methods ####################################
//
//Get the element i-th
amplitude quantumRegister::getElement(unsigned int element){
	return this->statesVector[element];
}

//Get the Magnitud or Modulus of the element i-th
double quantumRegister::magnitude(int element){
	return abs(this->statesVector[element]);
}

//Get the sum of magnitudes of the statesVector
double quantumRegister::magnitudSumatory(){
	int sum=0;
	for (amplitude n : this->statesVector) {
		sum += abs(n);
	}
	return sum;
}


//Set methods ####################################
int quantumRegister::insertElement(amplitude a){
	this->statesVector.push_back(a);
}

// Fill the states vector ramdonly
void quantumRegister::fillStatesVector(){
	int i;
	for (i=0; i < this->localNumQubits; i++){
		
	}
}

//Miscelaneous methods ###########################
//Print states vector
void quantumRegister::printStates(){
	std::cout << "v = { ";
	for (amplitude n : this->statesVector) {
		std::cout << n << ", ";
	}
	std::cout << "}; \n";
}

//Destructor #####################################
quantumRegister::~quantumRegister(){
}
