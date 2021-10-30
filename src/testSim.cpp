#include "quantumRegister.h"
#include <iostream>
#include <stdlib.h>
#include <mpi.h>
#include <zfp.h>
#include <zfparray2.h>
#include "array2d.h"


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
		int i, j;
		numberOfQubits = atoi(argv[1]);
		std::cout << "Instantiating qregs" << std::endl;
		QuantumRegister qreg1(numberOfQubits);
		QuantumRegister qreg2(numberOfQubits);

		std::cout << qreg1.getSize() << std::endl;

/*
		zfp::array2<double> compressedVector(2, 10, 0.0);
		raw::array2d vector(nx, ny);
		raw::array2d vector2(nx, ny);
*/

/*
		MPI_Init(&argc, &argv);
		MPI_Comm_size(MPI_COMM_WORLD, &pool_size);
		MPI_Comm_rank(MPI_COMM_WORLD, &pool_rank);
		
		MPI_Finalize();
*/

		//std::cout << "filling vector" << std::endl;
		//qreg1.fillStatesVector();
		//std::cout << "Printing vector" << std::endl;
		//qreg1.printStatesVector();
		//std::cout << "compressing vector" << std::endl;
		//compressedVector.set(&qreg1.statesVector[0]);
		//std::cout << "vector compressed" << std::endl;

/*
		std::cout << vector.size() << std::endl;
		std::cout << compressedVector.size() << std::endl;

		for (zfp::array2d::iterator it = compressedVector.begin(); it != compressedVector.end(); it++) {
			int i = it.i();
			int j = it.j();
			std::cout << compressedVector(i,j) << std::endl;
		}
*/

/*
		compressedVector.get(&qreg2.statesVector[0]);
		qreg2.printStatesVector();
*/


		return 0;
	}
}
