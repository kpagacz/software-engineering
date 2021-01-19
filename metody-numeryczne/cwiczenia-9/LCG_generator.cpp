#include "LCG_generator.h"

double LCG_generator::random()
{
	x = (mult * x + add) % mod;
	return (double)(x) / mod;
}

void LCG_generator::reset()
{
	x = seed;
}
