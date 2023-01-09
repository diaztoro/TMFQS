#include "quantumRegister.h"
#include <stdlib.h>
#include <mpi.h>
#include <zfp.h>
#include <zfp/array2.hpp>
#include "array2d.h"
#include <iostream>


using namespace std;

int main(int argc, char *argv[]){

	if(argc != 3){
		cout << "testSim <Number of Qubits> <index>" << endl;
		return 1;
	}
   else{
		int i, j;
		unsigned int numberOfQubits, index;
		numberOfQubits = atoi(argv[1]);
		index = atoi(argv[2]);
		Amplitude amp1;

		//QuantumRegister qreg1;
		//qreg1.setSize(numberOfQubits);
		QuantumRegister qreg1(numberOfQubits);
		qreg1.fillStatesVector();
		//cout << qreg1.getSize() << endl;
		qreg1.printStatesVector();
		amp1 = qreg1.amplitude(index);
		cout << amp1.real << amp1.imag << endl;

		/*
		cout << "Instantiating by copy" << endl;
		QuantumRegister qreg2(qreg1);
		cout << qreg2.getSize() << endl;
		cout << "Printing qreg2" << endl;
		qreg2.printStatesVector();
		*/


		return 0;
	}
}
