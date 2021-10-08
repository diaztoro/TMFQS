#ifndef QUANTUM_INCLUDE
#define QUANTUM_INCLUDE

#include <cstdio>
#include <cstdlib>
#include <functional>
#include "types.h"

using namespace std;

class quantumRegister {

	private:
		amplitudesVector statesVector;

	public:
		unsigned int globalNumQubits;
		unsigned int localNumQubits;

		//Constructors
		quantumRegister(unsigned int globalNumQubits);

		//Get methods
		amplitude getElement(unsigned int);

		//Set methods
		int insert(amplitude a);

		//Destructor
		~quantumRegister();
};

#endif
