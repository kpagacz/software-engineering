#ifndef LIST
#define LIST

template<class T>
class List
{
private:
	struct Node {
		Node* next;
		T value;
		Node(const T& new_el) : next(nullptr), value(new_el) {};
	};

	Node* head, * tail;
	size_t size_;

public:
	// constructors, destructors
	List() : head(nullptr), tail(nullptr), size_(0) {};
	~List();

	// setters, getters
	int size() const;

	// other
	void insert(const T& new_el);
	T pop_front();
};

#include "List.cpp"
#endif

