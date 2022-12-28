#ifndef TYPES_INCLUDE
#define TYPES_INCLUDE


#include <zfp.h>
#include <zfp/array2.hpp>
#include "array2d.h"

typedef struct {
	double real, imag;
} amplitude;

typedef struct {
	raw::array2d real, imag;
} matrixcd;

using AmplitudeVector = raw::array2d;
//using Matrix = raw::array2d;

using CompressedAmplitudesVector = zfp::array2d;
using CompressedMatrix = zfp::array2d;


#endif
