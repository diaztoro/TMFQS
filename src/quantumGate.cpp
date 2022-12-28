#include "quantumGate.h"

QuantumGate::QuantumGate(unsigned int dimension){
	this->dimension = dimension;
	this->gate.real.resize(this->dimension, this->dimension);
	this->gate.imag.resize(this->dimension, this->dimension);
}



/*
QuantumGate QuantumGate::operator*(amplitude scalar) {
	QuantumGate res(dimension);
	unsigned int i, j;
	for (i=0; i<dimension; i++) {
		for (j=0; j<dimension; j++) {
			res.realMatrix(i,j) = (realMatrix(i,j) * scalar.real) - (imagMatrix(i,j) * scalar.imag);
			res.imagMatrix(i,j) = (realMatrix(i,j) * scalar.imag) + (imagMatrix(i,j) * scalar.real);
		}
	}
	return res;
}

// Left scalar multiplication, nonmember function
QuantumGate operator*(amplitude x, QuantumGate &U) {
	return U * x;
}
*/
