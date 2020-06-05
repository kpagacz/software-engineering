#ifndef ROPE
#define ROPE
#include<iostream>
#include<cstddef>

template<typename T>
class Rope
{
private:
	struct Node {
		T value;
		Node* next;
		Node(const T& new_value) : value(new_value), next(nullptr) {};
		Node(const T& new_value, Node* new_next) : value(new_value), next(new_next) {};
	};
	Node* head;
	std::size_t size;

public:
	// constructors, destructors
	Rope() : head(nullptr), size(0) {};
	~Rope();

	// other
	void push(const T&);

	// operators
	friend std::ostream& operator<<(std::ostream& os, const Rope& rope) {
		for (Node* it = rope.head; it != nullptr; it = it->next) {
			os << it->value << " ";
		}
		os << std::endl;
		return os;
	};
};

#include "Rope.cpp"

#endif

template<typename T>
inline Rope<T>::~Rope()
{
}
