#ifndef LCG_GENERATOR
#define LCG_GENERATOR

class LCG
{
public:
	LCG(unsigned int _seed,
		unsigned int _mult = 869,
		unsigned int _add = 19,
		unsigned int _mod = 1318492) : mult(_mult), add(_add), mod(_mod), seed(_seed) {
		x = seed;
	}
	double random();
	void reset();
private:
	unsigned int mult, add, mod, seed, x;
};

#endif // LCG_GENERATOR