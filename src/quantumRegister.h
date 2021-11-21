#ifndef QUANTUM_INCLUDE
#define QUANTUM_INCLUDE

#include <cstdio>
#include <cstdlib>
#include <functional>
#include "types.h"

using namespace std;

class QuantumRegister {

	private:
		double localProbabilitySum;
		AmplitudeVector statesVector;

	public:
		unsigned int globalNumQubits;
		unsigned int localNumQubits;

		//Constructors ###################################
		QuantumRegister();
		QuantumRegister(const QuantumRegister&);

		int getSize();

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
		void setSize(unsigned int);

		// Fill the states vector ramdonly
		void fillStatesVector();

		//Miscelaneous methods ###########################
		//Print states vector
		void printStatesVector();

		//Destructor #####################################
		~QuantumRegister();
};

#endif
