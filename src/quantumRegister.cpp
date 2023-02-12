#include "quantumRegister.h"
#include "utils.h"

// Quantum Register class implementation
//
//Constructors ###################################
QuantumRegister::QuantumRegister() {
}

QuantumRegister::QuantumRegister(unsigned int n) {
	this->numQubits = n;
	amplitudes.resize(1, 2);
	amplitudes(0,0) = 1.0;
	amplitudes(0,1) = 0.0;
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


Amplitude QuantumRegister::amplitude(unsigned int state){
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


//Get the Magnitud or Modulus of the element i-th
double QuantumRegister::probability(unsigned int state){
	Amplitude amp = amplitude(state);
	return sqrt(pow(amp.real, 2) + pow(amp.imag, 2));
}

//Get the sum of magnitudes of the amplitudes
double QuantumRegister::magnitudSumatory(){
	int i, sum=0;
	for(i=0; i<this->numQubits; i++){
		sum += pow(this->amplitudes(i,0),2) + pow(this->amplitudes(i,1),2);
	}
	return sum;
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
std::ostream &operator << (std::ostream &os, QuantumRegister &reg) {
	int i, j;
	for(i=0; i < reg.numQubits; i++){
		cout << reg.states[i] << ": ";
		for(j=0; j < 2; j++){
			cout << reg.amplitudes(i,j) << " ";
		}
		cout << endl;
	}
	return os;
}

void QuantumRegister::printStatesVector(){
	cout << *this;
}


//Destructor #####################################
QuantumRegister::~QuantumRegister(){
}



//Quantum Gates operations
//
// Method to copy amplitudes vector
AmplitudesVector copyAmplitudes(AmplitudesVector amps){
	AmplitudesVector amps2;
	int i, j;

	amps2.resize(amps.size(), 2);
	for(i=0; i < amps.size(); i++){
		for(j=0; j < 2; j++){
			amps2(i,j) = amps(i,j);
		}
	}
	return amps2;
}

//Get all states accoding the number of qubits
StatesVector getAllStates(unsigned int qubits){
	StatesVector v;
	int i;

	for(i=0; i < qubits; i++){
		v[i] = i;
	}
	return v;
}

string QuantumRegister::getNthBit(unsigned int state, unsigned int qubit){
	unsigned int pos, bit;
	pos = this->numQubits - qubit - 1;   
	bit = (state >> pos) & 1;
	return to_string(bit);
}

// Method to apply a quantum gate to quantum register
void QuantumRegister::applyGate(QuantumGate g, IntegerVector qubits){

	if (g.dimension != (unsigned int)(1 << qubits.size())) { // 1 << qubits.size is pow(2, qubits.size())
		printf("Unitary matrix dimension is not correct to be applied to the inputs qubits\n");
		return; 
	}

	unsigned int state, i; 
	string s;
	unsigned int r, j; 
	StatesVector oldStates, tempStates;
	AmplitudesVector oldAmplitudes;
	Amplitude c;
	

	oldAmplitudes = copyAmplitudes(amplitudes);
	oldStates = states;
	tempStates = getAllStates(qubits.size());

	//for (state_map::iterator i = old.begin(); i != old.end(); ++i) {
	for( i = 0; i < oldStates.size(); i++ ){
		state = oldStates[i];

		for (unsigned int qubit : qubits){
			s += getNthBit(state, qubit);
		}

	/*
		state = i->first; 
		s = "";
		for (unsigned int q : qubits) s += state[q];
		r = binary_to_base10(s); // Find which number basis element s corresponds to.
	*/

	/*

		states[state] -= (1.0 - u[r][r]) * old[state];
		// if (states[state] == 0.0) states.erase(state); // Get rid of it.
		if (probability(state) < 1e-16) states.erase(state); // zero beyond machine precision.

		j = 0;
		for(string k : temp_states) {
			if (j != r) {
				s = state;
				for (unsigned int l = 0; l < k.size(); l++) s[qubits[l]] = k[l];
				c = u[j][r] * old[state];
				if (check_state(s)) {
					states[s] += c;
					// if (states[s] == 0.0) states.erase(s);
					if (probability(s) < 1e-16) states.erase(s); // zero beyond machine precision.
				} else if(c != 0.0) states[s] = c;
			}
			j++;
		}
	*/
	}
}



// Method to apply a Hadamard gate to specific qubit of a quantum register
void QuantumRegister::hadamar(unsigned int qubit){
}
