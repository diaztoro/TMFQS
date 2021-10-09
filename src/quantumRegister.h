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
		double localProbabilitySum;

	public:
		unsigned int globalNumQubits;
		unsigned int localNumQubits;

		//Constructors ###################################
		quantumRegister(unsigned int globalNumQubits);

		//Get methods ####################################
		//

		//Get the element i-th
		amplitude getElement(unsigned int);

		//Get the Magnitud or Modulus of the element i-th
		double magnitude(int element);

		//Get the sum of magnitudes of the statesVector
		double magnitudSumatory();

		//Set methods ####################################
		//

		// Insert an element in states vector
		int insertElement(amplitude a);

		// Fill the states vector ramdonly
		void fillStatesVector();

		//Miscelaneous methods ###########################
		//Print states vector
		void printStates();

		//Compress statesVector
			

		//Destructor #####################################
		~quantumRegister();
};

#endif
