#ifndef PLASZCZAK_H
#define PLASZCZAK_H

#include<iostream>
class Plaszczak
{
private:
	char body;
	int x_pos, y_pos;

public:
	Plaszczak(char c = '?', int x_pos = 1, int y_pos = 1) : body(c), x_pos(x_pos), y_pos(y_pos) {};
	virtual ~Plaszczak() {};
	int& getx() { return x_pos; };
	int& gety() { return y_pos; };

	// ruch

	// operatory
	friend std::ostream& operator<<(std::ostream& out, const Plaszczak& p) {
		out << p.body;
		return out;
	};
};

#endif // PLASZCZAK_H