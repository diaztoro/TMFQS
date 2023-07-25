#include "quantumRegister.h"
#include "utils.h"

// Quantum Register class implementation
//
//Constructors ###################################
// Default contructor
QuantumRegister::QuantumRegister() {
}

// Parametrized Constructor
QuantumRegister::QuantumRegister(unsigned int numQubits) {
	this->numQubits = numQubits;
	this->states.push_back(0);
	this->amplitudes.push_back(1.0);
	this->amplitudes.push_back(0.0);
}

//Copy Constructor 
QuantumRegister::QuantumRegister(const QuantumRegister& qreg) {
	this->amplitudes = qreg.amplitudes;
}

int QuantumRegister::getSize(){
	return this->amplitudes.size();
}

//Get methods ####################################
//
//Get the element i-th of linearized amplitudes vector
Amplitude QuantumRegister::getElement(unsigned int element){
	Amplitude amp;
	amp.real = this->amplitudes[element*2];
	amp.imag = this->amplitudes[element*2 + 1];
	return amp;
}


Amplitude QuantumRegister::amplitude(unsigned int state){
	Amplitude amp;
	int index;
	StatesVector::iterator i = find(this->states.begin(), this->states.end(), state);
	if (i != this->states.end()) {
		index = i - this->states.begin();
		amp.real = this->amplitudes[index];
		amp.imag = this->amplitudes[index + 1];
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
double QuantumRegister::probabilitySumatory(){
	unsigned int i;
	double sum = 0.0;
	for(i=0; i<this->states.size(); i++){
		sum += pow(this->amplitudes[i*2], 2) + pow(this->amplitudes[i*2 + 1], 2);
	}
	return sum;
}


//Set methods ####################################
void QuantumRegister::setSize(unsigned int numQubits){
	this->numQubits = numQubits;
	this->states.resize(pow(2,numQubits), 0);
	this->amplitudes.resize(pow(2,numQubits)*2, 0.0);
}


// Fill the states vector ramdonly
void QuantumRegister::fillStatesVector(){
	unsigned int i;
	if ( this->states.size() < this->numQubits ){
		this->amplitudes.resize(this->numQubits*2);
	}
	for (i=1; i < this->numQubits; i++){
		this->states.push_back(i);
		this->amplitudes.push_back(i);
		this->amplitudes.push_back(i);
	}
}

//Miscelaneous methods ###########################
//Print states vector
std::ostream &operator << (std::ostream &os, QuantumRegister &reg) {
	unsigned int i = 0;
	for(auto &element : reg.states){
		cout << element << ": ";
		cout << reg.amplitudes[i*2] << " " << reg.amplitudes[i*2 + 1] << endl;
		i++;
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

//Get all states according the number of qubits
StatesVector getAllStates(unsigned int qubits){
	StatesVector v;
	int i;

	for(i=0; i < (1 << qubits); i++){
		v.push_back(i);
	}
	return v;
}


string QuantumRegister::getNthBit(unsigned int state, unsigned int qubit){
	unsigned int pos, bit;
	pos = this->numQubits - qubit - 1;   
	bit = (state >> pos) & 1;
	return to_string(bit);
}

int QuantumRegister::findState(unsigned int state){
	int index;
	auto it = std::find(this->states.begin(), this->states.end(), state); 
	if (it != this->states.end()) {
		index = it - this->states.begin();
	}
	else {
		index = -1;
	}
	return index;
}



double QuantumRegister::getProbability(unsigned int state){
	Amplitude amp;
	amp.real = this->amplitudes[state];
	amp.imag = this->amplitudes[state+1];
	return absoluteValue(amp);
}



// Method to apply a quantum gate to quantum register
void QuantumRegister::applyGate(QuantumGate gate, IntegerVector qubits){

	if (gate.dimension != (unsigned int)(1 << qubits.size())) { // 1 << qubits.size is pow(2, qubits.size())
		printf("Unitary matrix dimension is not correct to be applied to the inputs qubits\n");
		return; 
	}

	unsigned int state, newState, pos, tempBit, stateCounter;;
	int stateIndex, newStateIndex;
	string s;
	unsigned int i, j, l, r;
	StatesVector oldStates, tempStates;
	AmplitudesVector oldAmplitudes;
	Amplitude c, auxAmp1, auxAmp2, auxAmp3;
	
	// Copy the current states
	oldAmplitudes = this->amplitudes;
	oldStates = this->states;

	tempStates = getAllStates(qubits.size());


	// For all states do
	for( stateCounter = 0; stateCounter < oldStates.size(); stateCounter++ ){
		state = oldStates[stateCounter];
		stateIndex = findState(state);
		s = "";

		// Get a string containing the n-th bit of the state according the qubits vector
		for (unsigned int qubit : qubits){
			s += getNthBit(state, qubit);
		}
		// Find which number basis element s corresponds to.
		r = binaryToDecimal(s);

		auxAmp1.real = 1.0 - gate[r][r].real;
		auxAmp1.imag =  0.0 - gate[r][r].imag;
		auxAmp2.real = oldAmplitudes[stateIndex*2];
		auxAmp2.imag = oldAmplitudes[stateIndex*2 + 1];
		auxAmp3.real = 0.0;
		auxAmp3.imag = 0.0;
		auxAmp3 = amplitudeMult(auxAmp1, auxAmp2);
		this->amplitudes[stateIndex*2] = this->amplitudes[stateIndex*2] - auxAmp3.real;
		this->amplitudes[stateIndex*2+1] = this->amplitudes[stateIndex*2+1] - auxAmp3.imag;
	
		/*
		// NOT YET CONSIDERED 
		if (probability(state) < 1e-16) states.erase(state); // zero beyond machine precision.
		*/

		j = 0;
		for(int k : tempStates){
			if (j != r) {
				newState = state;
				/*
				// COPY ALL BITS FROM k TO newState AT POSITION pos WHICH CORRESPOND TO THE QUBIT WHERE TO APPLY THE GATE
				// qubits.size() IS THE NUMBER OF BITS OF k (BITS TO COPY)
				pos = this->numQubits - qubits.size() - qubits[0];
				newState = copyBits(newState, k, pos, qubits.size());
				*/

				// COPY ALL BITS FROM k TO newState AT POSITION pos WHICH CORRESPOND TO THE QUBIT WHERE TO APPLY THE GATE
				// qubits.size() IS THE NUMBER OF BITS OF k (BITS TO COPY)
				// For all bits of k
				// l Iterates backward over the bits of k (the most significative bits is on the right)
				// And i iterates forward over qubits vector
				for(l = qubits.size() - 1, i = 0; l >= 0, i < qubits.size(); l--, i++){ 
					// get the i-th bit
					tempBit = (k >> l)&1; 
					pos = this->numQubits - qubits[i] - 1;
					newState = copyBits(newState, tempBit, pos, 1);
				}
				//c = u[j][r] * old[state];
				c.real = gate[j][r].real * oldAmplitudes[stateIndex*2];
				c.imag = gate[j][r].imag * oldAmplitudes[stateIndex*2+1];
				newStateIndex = findState(newState);
				if(newStateIndex != -1){
					this->amplitudes[newStateIndex*2] += c.real;
					this->amplitudes[newStateIndex*2+1] += c.imag;
				}
				else{
					this->states.push_back(newState);
					this->amplitudes.push_back(c.real);
					this->amplitudes.push_back(c.imag);
				}
			}
			j++;
		}
	}
}



// Method to apply a Hadamard gate to specific qubit of a quantum register
void QuantumRegister::Hadamard(unsigned int qubit){
	IntegerVector v;
	v.push_back(qubit);
	applyGate(QuantumGate::Hadamard(), v);
}


// Method to apply a ControlledPhaseShift gate to specific qubit of a quantum register
void QuantumRegister::ControlledPhaseShift(unsigned int controlQubit, unsigned int targetQubit, double theta){
	IntegerVector v;
	v.push_back(controlQubit);
	v.push_back(targetQubit);
	applyGate(QuantumGate::ControlledPhaseShift(theta), v);
}


void QuantumRegister::ControlledNot(unsigned int controlQubit, unsigned int targetQubit) {
	IntegerVector v; v.push_back(controlQubit); v.push_back(targetQubit);
	applyGate(QuantumGate::ControlledNot(), v);
}


void QuantumRegister::Swap(unsigned int qubit1, unsigned int qubit2) {
	ControlledNot(qubit1, qubit2);
	ControlledNot(qubit2, qubit1);
	ControlledNot(qubit1, qubit2);
}
