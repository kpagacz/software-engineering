#ifndef ROPE
#define ROPE

class Rope {
private:
	struct Node {
		Node(const int& new_el) : value(new_el), next(nullptr) {};
		int value;
		Node* next;
	};

	Node* head;
	size_t size;

public:
	Rope() : head(nullptr), size(0) {};
	~Rope();

	void print() const;
	void insert(const int&);
	void funny_remove(const int&);
	void funny_move();
	void exchangeConstantVectors(Rope& other);
	void exchangeConstantVectors2(Rope& other);
};


#endif