#ifndef TYPES_INCLUDE
#define TYPES_INCLUDE


#include <zfp.h>
#include <zfparray2.h>
#include <zfpcarray2.h>
#include "array2d.h"

typedef struct {
	double real, imag;
} amplitude;

using AmplitudeVector = raw::array2d;
using Matrix = raw::array2d;

using CompressedAmplitudesVector = zfp::array2d;
using CompressedMatrix = zfp::array2d;


#endif
