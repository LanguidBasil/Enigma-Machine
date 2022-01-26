#include "MathExtensions.h"

bool InRangeInclusive(int input, int lowInclusive, int highInclusive)
{
	return input >= lowInclusive && input <= highInclusive;
}