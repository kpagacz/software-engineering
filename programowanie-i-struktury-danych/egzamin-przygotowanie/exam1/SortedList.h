#ifndef SORTED_LIST__
#define SORTED_LIST__
template<class T>
class SortedList {
private:
	struct Node {
		Node(const T& new_el) : value(new_el), next(nullptr) {};
		T value;
		Node* next;
	};
	
	Node* head;
	size_t size;
public:
	// constructors, destructors
	SortedList() : head(nullptr), size(0) {};
	~SortedList();

	// setters, getters
	size_t get_size() const;

	// other
	void print() const;
	void insert(const T& new_el);
	T pop_front();
};

#include "SortedList.cpp"
#endif
