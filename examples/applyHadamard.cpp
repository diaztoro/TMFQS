#include "tmfqs.h"
#include <stdlib.h>
#include <iostream>


using namespace std;

//TMFQS
int main(int argc, char *argv[]){

	if(argc != 3){
		cout << "./applyHadamard <Number of Qubits> <qubit>" << endl;
		return 1;
	}
   else{
		int i, j;
		unsigned int numberOfQubits, qubit;
		numberOfQubits = atoi(argv[1]);
		qubit = atoi(argv[2]);
		Amplitude amp;

		amp.real = 0.653281;
		amp.imag = 0.270598;
		QuantumRegister qreg(numberOfQubits, 9, amp);
		qreg.printStatesVector();
		std::cout << std::endl;
		qreg.Hadamard(qubit);
		/*
		for(int i=0; i<numberOfQubits; i++){
			qreg.Hadamard(i);
		}
		*/
		qreg.printStatesVector();
		//qreg.Hadamard(qubit);
		//qreg.printStatesVector();


		return 0;
	}
}
