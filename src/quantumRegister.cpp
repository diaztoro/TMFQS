#include <iostream>
#include "quantumRegister.h"
#include "utils.h"

// Quantum Register class implementation
//
//Constructors ###################################
QuantumRegister::QuantumRegister() {
}

//Constructor by copy
QuantumRegister::QuantumRegister(const QuantumRegister& qreg) {
	int i, j;
	localNumQubits = qreg.localNumQubits;
	statesVector.resize(pow(2,this->localNumQubits), 2);
	for(i=0; i < localNumQubits; i++){
		for(j=0; j < 2; j++){
			statesVector(i,j) = qreg.statesVector(i,j);
		}
	}
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
	return sqrt(pow(this->statesVector(element,0), 2) + pow(this->statesVector(element,1), 2));
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
void QuantumRegister::setSize(unsigned int numQubits){
	this->localNumQubits = numQubits;
	this->statesVector.resize(pow(2,this->localNumQubits), 2);
}


// Fill the states vector ramdonly
void QuantumRegister::fillStatesVector(){
	int i, j;
	for (i=0; i < this->localNumQubits; i++){
		for (j=0; j < 2; j++){
			statesVector(i,j) = getRandomNumber();
		}
	}
}

//Miscelaneous methods ###########################
//Print states vector
void QuantumRegister::printStatesVector(){
	int i, j;
	for(i=0; i < this->localNumQubits; i++){
		for(j=0; j < 2; j++){
			cout << this->statesVector(i,j) << " ";
		}
		cout << endl;
	}
}


//Destructor #####################################
QuantumRegister::~QuantumRegister(){
}
