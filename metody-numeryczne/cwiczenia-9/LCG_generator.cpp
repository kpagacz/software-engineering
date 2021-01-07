#include "LCG_generator.h"

int LCG_generator::random()
{
	x = (mult * x + add) % mod;
	return x;
}

void LCG_generator::reset()
{
	x = seed;
}
