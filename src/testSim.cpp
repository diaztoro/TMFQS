#include "quantumRegister.h"
#include <iostream>
#include <stdlib.h>
#include <mpi.h>


using namespace std;

int main(int argc, char *argv[]){
	int numberOfQubits;
	int pool_rank;
	int pool_size;

	if(argc != 2){
		cout << "testSim <Number of Qubits>" << endl;
		return 1;
	}
   else{
		numberOfQubits = atoi(argv[1]);
		quantumRegister qreg(numberOfQubits);
/*
		MPI_Init(&argc, &argv);
		MPI_Comm_size(MPI_COMM_WORLD, &pool_size);
		MPI_Comm_rank(MPI_COMM_WORLD, &pool_rank);
		
		MPI_Finalize();
*/

		return 0;
	}
}
