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
	Rope() : size(0), head(nullptr) {};
	~Rope();

	void print() const;
	void insert(const int&);
	void funny_remove();
	void moveWithStep(const int& K);
	void exchangeGroups(Rope& other);
};


#endif