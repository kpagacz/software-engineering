#ifndef  SZNUR
#define SZNUR

class sznur
{
private:
	struct Node {
		Node(const int& el) : value(el), next(nullptr) {};
		int value;
		Node* next;
	};
	Node* head;
	size_t size;
public:
	sznur() : head(nullptr), size(0) {};
	void wypisz() const;
	void wstaw(const int&);
	friend void usun(sznur&);
};

#endif