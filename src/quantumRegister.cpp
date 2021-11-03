#include <iostream>
#include "quantumRegister.h"
#include "utils.h"

// Quantum Register class implementation
//
//Constructors ###################################
QuantumRegister::QuantumRegister(unsigned int numQubits) {
	int i;
	this->localNumQubits = numQubits;
	this->statesVector.push_back(1.0);
	for(i=1; i<this->localNumQubits*2; i++){
		this->statesVector.push_back(0.0);
	}
}

//Constructor by copy
QuantumRegister::QuantumRegister(const QuantumRegister& qreg) {
	int i;
	localNumQubits = qreg.localNumQubits;
	//statesVector = qreg.statesVector;
	this->statesVector.push_back(1.0);
	for(i=1; i<this->localNumQubits*2; i++){
		this->statesVector.push_back(0.0);
	}
	compressedStatesVector = qreg.compressedStatesVector;
}

int QuantumRegister::getSize(){
	return this->statesVector.size();
}

//Get methods ####################################
//
//Get the element i-th
amplitude QuantumRegister::getElement(unsigned int element){
	amplitude amp;
	amp.real = this->statesVector[element];
	amp.imag = this->statesVector[element*2];
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
		sum += pow(this->statesVector[i],2) + pow(this->statesVector[i*2],2);
	}
	return sum;
}


//Set methods ####################################

// Fill the states vector ramdonly
void QuantumRegister::fillStatesVector(){
	int i;
	for (i=0; i < this->localNumQubits*2; i++){
		statesVector[i] = getRandomNumber();
	}
}

//Miscelaneous methods ###########################
//Print states vector
void QuantumRegister::printStatesVector(){
	int i;
	for(i=0; i<localNumQubits; i++){
		std::cout << statesVector[i] << " " << statesVector[i*2] << std::endl;
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
