#ifndef CIAG
#define CIAG

#include<iostream>

class Ciag
{
private:
	struct Node {
		int value;
		Node* next;
		Node(int _value, Node* _next = nullptr) : value(_value), next(_next) {}
	};

	Node* head;
	size_t size;

	void push(const int&);

public:
	// constructors
	Ciag() : head(nullptr), size(0) {}
	Ciag(int, int, int);
	Ciag(const Ciag&); // copy constructor

	~Ciag();

	// operators
	friend std::ostream& operator<<(std::ostream& out, const Ciag& ciag);
	Ciag& operator++(); // prefix increment
	int& operator[](int);
	Ciag operator++(int); // postfix increment
	
};

#endif CIAG