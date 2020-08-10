#ifndef ROPE
#define ROPE

class Rope {
private:
	struct Node {
		Node() : value(0), next(nullptr) {};
		Node(const int& new_el) : value(new_el), next(nullptr) {};
		int value;
		Node* next;
	};
	size_t size;
	Node* head;

public:
	Rope() : size(0), head(nullptr) {};
	~Rope();
	void print() const;
	void insert(const int&);
	void funny_remove(const int&, const int&);
	void remove_node(Node* pred, Node* succ);
	void move();
	void move_pairs(Rope& other, const int& M);
};


#endif // !ROPE
