#include <iostream>
#include "quantumRegister.h"
#include "utils.h"

// Quantum Register class implementation
//
//Constructors ###################################
QuantumRegister::QuantumRegister(unsigned int numQubits) {
	int i;
	this->localNumQubits = numQubits;
	//this->statesVector(localNumQubits, localNumQubits, 0.0, 0, 0);
/*
	for(i=0; i<this->localNumQubits; i++){
		this->statesVector(i,0) = 0.0; 
		this->statesVector(i,1) = 0.0; 
		std::cout << this->statesVector(i,0) << " " << this->statesVector(i,1) << std::endl;
	}
*/
}

int QuantumRegister::getSize(){
	return this->statesVector.size();
}

//Get methods ####################################
//
//Get the element i-th
amplitude QuantumRegister::getElement(unsigned int element){
	amplitude amp;
	amp.real = this->statesVector(element,0);
	amp.imag = this->statesVector(element,1);
	return amp;
}

//Get the Magnitud or Modulus of the element i-th
double QuantumRegister::magnitude(int element){
	return abs(this->statesVector[element]);
}

//Get the sum of magnitudes of the statesVector
double QuantumRegister::magnitudSumatory(){
	int i, sum=0;
	for(i=0; i<this->localNumQubits; i++){
		sum += pow(this->statesVector(i,0),2) + pow(this->statesVector(i,1),2);
	}
	return sum;
}


//Set methods ####################################

// Fill the states vector ramdonly
void QuantumRegister::fillStatesVector(){
	int i;
	std::cout << "Filling " << std::endl;
	for (i=0; i < this->localNumQubits; i++){
		statesVector(i,0) = getRandomNumber();
		statesVector(i,1) = getRandomNumber();
		std::cout << statesVector(i,0) << " " << statesVector(i,1) << std::endl;
	}
}

//Miscelaneous methods ###########################
//Print states vector
void QuantumRegister::printStatesVector(){
	int i;
	for(i=0; i<localNumQubits; i++){
		std::cout << statesVector(i,0) << " " << statesVector(i,1) << std::endl;
	}
}

//Compress statesVector
void QuantumRegister::compress(){
	compressedStatesVector.set(&statesVector[0]);
}

//Uncompress statesVector
void QuantumRegister::uncompress(){
	compressedStatesVector.get(&statesVector[0]);
}

//Destructor #####################################
QuantumRegister::~QuantumRegister(){
}
