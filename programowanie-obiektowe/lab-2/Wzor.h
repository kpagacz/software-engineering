#ifndef WZOR
#define WZOR
class Wzor
{
private:
	unsigned int length;
	char sign;

public:
	Wzor(const char& _sign = '?', const unsigned int& _length = 3) : sign(_sign), length(_length) {} // alternatively
	~Wzor();

	void opis() const;
	void drukuj() const;

	void ustaw(const char& _sign, const unsigned int& _length);
};

#endif
