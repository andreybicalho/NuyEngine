#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace nuy { namespace maths {
	
	inline float ToRadians(float degrees)
	{
		return (float) (degrees * (M_PI / 180.0f));
	}

} }