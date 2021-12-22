#ifndef QUANTUM_GATE_INCLUDE
#define QUANTUM_GATE_INCLUDE

#include "types.h"

class QuantumGate {

	private:
		matrixcd gate;
		//Matrix realMatrix;
		//Matrix imagMatrix;

	public:
		unsigned int dimension;
		QuantumGate(unsigned int dimension);
/*
		amp * operator[](unsigned int i);
		QuantumGate operator*(amp x);
		QuantumGate operator*(QuantumGate &U);
		void print_matrix();
		friend std::ostream &operator<<(std::ostream &os, QuantumGate &U);

		static QuantumGate Identity(unsigned int dimension);
		static QuantumGate Hadamard();
		static QuantumGate PauliX();
		static QuantumGate PauliY();
		static QuantumGate PauliZ();
		static QuantumGate PhaseShift(double theta);
		static QuantumGate PiOverEight();
		static QuantumGate ControlledNot();
		static QuantumGate Toffoli();
		static QuantumGate ControlledPhaseShift(double theta);
		static QuantumGate Swap();
		static QuantumGate Ising(double theta);
		static QuantumGate QFT(unsigned int num_qubits);
		static QuantumGate IQFT(unsigned int num_qubits);

		// Matrices to be created upon initialization.
		// const static QuantumGate MHadamard;
*/

};

// For left multiplication.
//QuantumGate operator*(amp x, QuantumGate &U);

#endif
