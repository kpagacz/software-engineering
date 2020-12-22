#ifndef STACKTP
#define STACKTP

#include <iostream>
#include <stdexcept>

template <typename T> class StackTP;
template <typename T> std::ostream& operator<<(std::ostream& out, const StackTP<T>& stack);

template<typename T>
class StackTP {
public:
	StackTP();
	~StackTP();

	// operators
	StackTP<T>& operator+(const T& _el);
	T operator--();
	T& operator[](unsigned int);

	friend std::ostream& operator<< <T>(std::ostream& out, const StackTP<T>& stack);

	// methods
	void empty();

private:
	template <typename U>
	class Node {
	public:
		Node(U _el, Node* _next) : el(_el), next(_next) {}
		U el;
		Node* next;
	};

	size_t size;
	Node<T>* top;
};


template<typename T>
inline StackTP<T>::StackTP()
{
	top = nullptr;
	size = 0;
}

template<typename T>
inline StackTP<T>::~StackTP()
{
	Node<T>* it = top, * destr = nullptr;
	while (it != nullptr) {
		destr = it;
		it = it->next;
		delete destr;
		destr = nullptr;
	}
}

template<typename T>
inline StackTP<T>& StackTP<T>::operator+(const T& _el)
{
	top = new Node<T>(_el, top);
	size++;
	return *this;
}

template<typename T>
inline T StackTP<T>::operator--()
{
	if (size == 0)
		throw std::out_of_range("Stack is empty");

	T value = top->el;
	Node<T>* destr = top;
	top = top->next;
	size--;
	delete destr;
	destr = nullptr;
	return value;
}

template<typename T>
inline T& StackTP<T>::operator[](unsigned int id)
{
	if (id > size || id < 0)
		throw std::out_of_range("id out of range");
	Node<T>* it = top;
	while (id > 0) {
		id--;
		it = it->next;
	}

	if (it != nullptr)
		return it->el;
	else
		throw std::runtime_error("NULL element in the stack.");
}

template<typename T>
inline void StackTP<T>::empty()
{
	while (size > 0)
		--* this;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const StackTP<T>& stack)
{
	typename StackTP<T>::template Node<T> *it = stack.top;
	while (it != nullptr) {
		out << it->el << " ";
		it = it->next;
	}
	out << "\n";
	return out;
}

#endif // STACKTP