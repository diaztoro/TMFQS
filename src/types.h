#ifndef TYPES_INCLUDE
#define TYPES_INCLUDE


#include <zfp.h>
#include <zfparray2.h>
#include <zfpcarray2.h>
#include <vector>

typedef struct {
	double real, imag;
} amplitude;

typedef std::vector<double> amplitudeVector;
typedef zfp::array2d CompressedAmplitudesVector;


#endif
