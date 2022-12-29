#include "quantumRegister.h"
#include <stdlib.h>
#include <mpi.h>
#include <zfp.h>
#include <zfp/array2.hpp>
#include "array2d.h"
#include <iostream>


using namespace std;

/*
void print2(zfp::array2<double>::pointer p, size_t n)
{ 
	while (n--) 
		cout << *p++ << endl;
}
*/

int main(int argc, char *argv[]){
	int numberOfQubits;
	int pool_rank;
	int pool_size;

	if(argc != 2){
		cout << "testSim <Number of Qubits>" << endl;
		return 1;
	}
   else{
		int i, j;
		numberOfQubits = atoi(argv[1]);

		QuantumRegister qreg1;
		qreg1.setSize(numberOfQubits);
		qreg1.fillStatesVector();
		cout << qreg1.getSize() << endl;
		qreg1.printStatesVector();

		cout << "Instantiating by copy" << endl;
		QuantumRegister qreg2(qreg1);
		cout << qreg2.getSize() << endl;
		cout << "Printing qreg2" << endl;
		qreg2.printStatesVector();

/*
		MPI_Init(&argc, &argv);
		MPI_Comm_size(MPI_COMM_WORLD, &pool_size);
		MPI_Comm_rank(MPI_COMM_WORLD, &pool_rank);
		
		MPI_Finalize();
*/

		return 0;
	}
}
