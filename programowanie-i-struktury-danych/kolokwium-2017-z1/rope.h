#ifndef ROPE
#define ROPE

class Rope {
private:
	struct Node {
		int value;
		Node* next;
		Node(const int& new_el) : value(new_el), next(nullptr) {};
	};
	Node* head;
	size_t size;

public:
	Rope() : head(nullptr), size(0) {};
	void print() const;
	void insert(const int&);
	void funny_remove(const unsigned int&);
	void moveThrees();
	void exchangePairs(Rope&);
};

#endif