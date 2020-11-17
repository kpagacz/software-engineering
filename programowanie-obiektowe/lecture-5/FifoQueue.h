#ifndef FIFO
#define FIFO

#include<iostream>
#include<stdexcept>

template<class T>
class FifoQueue
{
private:
	struct Node {
		T value;
		Node* next;
		Node(T el, Node* _next = nullptr) : value(el), next(_next) {}
	};

	size_t size;
	Node* head, * tail;

public:
	// constructors, destructors
	FifoQueue() : size(0), head(nullptr), tail(nullptr) {};
	FifoQueue(const FifoQueue& other);
	~FifoQueue();

	// adding, removing
	void push(const T&);
	T pop();
	void empty();

	// operators
	friend std::ostream& operator<<(std::ostream& out, const FifoQueue& queue) {
		Node* it = queue.head;
		while (it != nullptr) {
			out << it->value << " ";
			it = it->next;
		}

		out << "\n";

		return out;
	}
	FifoQueue<T>& operator=(const FifoQueue&);
};

#endif // FIFO

template<class T>
inline FifoQueue<T>::FifoQueue(const FifoQueue& other)
{
	size = 0;
	head = nullptr;
	tail = nullptr;

	Node* other_it = other.head;
	while (other_it != nullptr) {
		push(other_it->value);
		other_it = other_it->next;
	}
}

template<class T>
inline FifoQueue<T>::~FifoQueue()
{
	Node* destr = nullptr, * succ = head;
	while (succ != nullptr) {
		destr = succ;
		succ = succ->next;
		delete destr;
		destr = nullptr;
	}
}

template<class T>
inline void FifoQueue<T>::push(const T& el)
{
	Node* creator = new Node(el);

	if (size == 0) {
		size++;
		head = creator;
		tail = creator;
		return;
	}

	size++;
	tail->next = creator;
	tail = creator;
}

template<class T>
inline T FifoQueue<T>::pop()
{
	if (size == 0) {
		throw std::out_of_range("Queue is empty\n");
	}

	Node* destr = head;
	T value = head->value;
	
	head = head->next;
	if (size == 1) {
		tail = nullptr;
	}

	delete destr;
	destr = nullptr;
	size--;

	return value;
}

template<class T>
inline void FifoQueue<T>::empty()
{
	Node* succ = head, * destr = nullptr;

	while (head != nullptr) {
		destr = succ;
		succ = succ->next;
		delete destr;
		destr = nullptr;
	}

	size = 0;
}

template<class T>
inline FifoQueue<T>& FifoQueue<T>::operator=(const FifoQueue& other)
{
	if (this == &other) {
		return *this;
	}

	empty();
	Node* other_it = other.head;
	while (other_it != nullptr) {
		push(other_it->value);
		other_it = other_it->next;
	}

	return *this;
}
