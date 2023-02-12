#ifndef TYPES_INCLUDE
#define TYPES_INCLUDE


#include <zfp.h>
#include <zfp/array2.hpp>
#include "array2d.h"
#include <map>
#include <string>

typedef struct {
        double real, imag;
} Amplitude;

using CompressedAmplitudesVector = zfp::array2d;
using AmplitudesVector = raw::array2d;
typedef std::vector<int> StatesVector;
typedef std::vector<int> IntegerVector;


#endif
