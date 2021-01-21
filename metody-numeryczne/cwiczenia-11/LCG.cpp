#include "LCG.h"

double LCG::random()
{
	x = (mult * x + add) % mod;
	return (double)(x) / mod;
}

void LCG::reset()
{
	x = seed;
}
