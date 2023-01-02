#include "quantumRegister.h"
#include "utils.h"

// Quantum Register class implementation
//
//Constructors ###################################
QuantumRegister::QuantumRegister() {
}

QuantumRegister::QuantumRegister(unsigned int n) {
	this->numQubits = n;
}

//Constructor by copy
QuantumRegister::QuantumRegister(const QuantumRegister& qreg) {
	int i, j;
	numQubits = qreg.numQubits;
	amplitudes.resize(pow(2,this->numQubits), 2);
	for(i=0; i < numQubits; i++){
		for(j=0; j < 2; j++){
			amplitudes(i,j) = qreg.amplitudes(i,j);
		}
	}
}

int QuantumRegister::getSize(){
	return this->amplitudes.size();
}

//Get methods ####################################
//
//Get the element i-th
Amplitude QuantumRegister::getElement(unsigned int element){
	Amplitude amp;
	amp.real = this->amplitudes(element,0);
	amp.imag = this->amplitudes(element,1);
	return amp;
}

//Get the Magnitud or Modulus of the element i-th
double QuantumRegister::magnitude(int element){
	return sqrt(pow(this->amplitudes(element,0), 2) + pow(this->amplitudes(element,1), 2));
}

//Get the sum of magnitudes of the amplitudes
double QuantumRegister::magnitudSumatory(){
	int i, sum=0;
	for(i=0; i<this->numQubits; i++){
		sum += pow(this->amplitudes(i,0),2) + pow(this->amplitudes(i,1),2);
	}
	return sum;
}

Amplitude QuantumRegister::amplitude(int state){
	Amplitude amp;
	int index;
	StatesVector::iterator i = find(this->states.begin(), this->states.end(), state);
	if (i != this->states.end()) {
		index = i - this->states.begin();
		amp.real = this->amplitudes(index,0);
		amp.imag = this->amplitudes(index,1);
	}
	else {
		amp.real = -1.0;
		amp.imag = -1.0;
   }
	return amp;
}


//Set methods ####################################
void QuantumRegister::setSize(unsigned int numQubits){
	this->numQubits = numQubits;
	this->amplitudes.resize(this->numQubits, 2);
	this->states.resize(this->numQubits);
}


// Fill the states vector ramdonly
void QuantumRegister::fillStatesVector(){
	int i, j;
	if ( this->states.size() < this->numQubits ){
		this->amplitudes.resize(this->numQubits, 2);
	}
	for (i=0; i < this->numQubits; i++){
		this->states.push_back(i);
		for (j=0; j < 2; j++){
			this->amplitudes(i,j) = getRandomNumber();
		}
	}
}

//Miscelaneous methods ###########################
//Print states vector
void QuantumRegister::printStatesVector(){
	int i, j;
	for(i=0; i < this->numQubits; i++){
		cout << this->states[i] << ": ";
		for(j=0; j < 2; j++){
			cout << this->amplitudes(i,j) << " ";
		}
		cout << endl;
	}
}


//Destructor #####################################
QuantumRegister::~QuantumRegister(){
}
