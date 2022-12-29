#ifndef TYPES_INCLUDE
#define TYPES_INCLUDE


#include <zfp.h>
#include <zfp/array2.hpp>
#include "array2d.h"
#include <map>
#include <string>

typedef struct {
        double real, imag;
} amplitude;

using AmplitudeVector = raw::array2d;
using CompressedAmplitudesVector = zfp::array2d;
typedef std::map<std::string, AmplitudeVector> state_map;


#endif
