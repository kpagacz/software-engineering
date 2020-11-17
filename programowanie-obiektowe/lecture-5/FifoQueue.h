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
		Node(T el, Node* _next) : value(el), next(_next) {}
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

	// operators
	friend std::ostream& operator<<(std::ostream&, const FifoQueue& queue) {
		Node* it = head;
		while (it != nullptr) {
			std::cout << it->value << " ";
			it = it->next;
		}

		std::cout << "\n";
	}
	FifoQueue& operator=(const FifoQueue&);
};

#endif // FIFO

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
		head = creator;
		tail = creator;
		return;
	}

	tail->next = creator;
	tail = creator;
	size++;
}

template<class T>
inline T FifoQueue<T>::pop()
{
	if (size == 0) {
		return std::out_of_range("Queue is empty\n");
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
