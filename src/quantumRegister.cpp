#include "quantumRegister.h"
#include <iostream>

// Quantum Register class implementation
// Constructors
quantumRegister::quantumRegister(unsigned int numQubits) {
	this->globalNumQubits = numQubits;
	this->statesVector.push_back(amplitude(1,0)); 
}

//Get methods
amplitude quantumRegister::getElement(unsigned int element){
	return this->statesVector[element];
}

//Set methods
int quantumRegister::insert(amplitude a){
	this->statesVector.push_back(a);
}

//Destructor
quantumRegister::~quantumRegister() {
}
