#include "MathExtensions.h"

namespace MathExt
{
	bool InRangeInclusive(int input, int lowInclusive, int highInclusive)
	{
		return input >= lowInclusive && input <= highInclusive;
	}
}
