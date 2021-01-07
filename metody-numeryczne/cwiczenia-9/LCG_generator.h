#ifndef LCG_GENERATOR
#define LCG_GENERATOR

class LCG_generator
{
public:
	LCG_generator(int _seed, int _mult = 869, int _add = 19, int _mod = 1318492) : mult(_mult), add(_add), mod(_mod), seed(_seed) { x = seed; }
	int random();
	void reset();
private:
	int mult, add, mod, seed, x;
};

#endif // LCG_GENERATOR