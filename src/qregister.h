#ifndef QUANTUM_INCLUDE
#define QUANTUM_INCLUDE

#include <cstdio>
#include "types.h"
#include <functional>

using namespace std;

class qRegister {

	private:
		stateVector amplitudes;

	public:
		unsigned int num_qubits;
		static vec_states all_states(unsigned int n);
		qRegister(unsigned int num_qubits);
		double probability(string state);
		string measure();
};

#endif
