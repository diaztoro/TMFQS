#include "quantumRegister.h"
#include <iostream>
#include <stdlib.h>
#include <mpi.h>
#include <zfp.h>
#include <zfparray2.h>
#include "array2d.h"


using namespace std;

void print2(zfp::array2<double>::pointer p, size_t n)
{ 
	while (n--) 
		std::cout << *p++ << std::endl;
}

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
		//QuantumRegister qreg1(numberOfQubits);

/*
		qreg1.fillStatesVector();
		//qreg1.printStatesVector();
		qreg1.compress();
		QuantumRegister qreg2(qreg1);
		qreg2.uncompress();
		qreg2.printStatesVector();
*/

/*
		std::vector<double> v1(numberOfQubits*2, 1.0);
		std::vector<double> v2;
*/
		zfp::array2<double> cv(numberOfQubits, 2, 64.0);
		for (zfp::array2<double>::iterator p = cv.begin(); p != cv.end(); p++)
			*p = rand();
		std::cout << "cv size " << cv.size() << " x " << cv.size_x() << " y " << cv.size_y() << std::endl;
		//print2(&cv[0], cv.size());

		raw::array2d v(numberOfQubits, 2);
		for (raw::array2d::iterator p = v.begin(); p != v.end(); p++) {
			*p = rand();
		}
		cout << sizeof(cv) << endl;
		cout << sizeof(v) << endl;


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
		compressedVector.get(&qreg2.statesVector[0]);
		qreg2.printStatesVector();
*/


		return 0;
	}
}
