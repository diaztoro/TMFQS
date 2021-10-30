#ifndef TYPES_INCLUDE
#define TYPES_INCLUDE


#include <zfp.h>
#include <zfparray2.h>
#include <zfpcarray2.h>
#include "array2d.h"

typedef struct {
	double real, imag;
} amplitude;

typedef raw::array2d AmplitudesVector;
typedef zfp::array2d CompressedAmplitudesVector;


#endif
