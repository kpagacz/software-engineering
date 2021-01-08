#ifndef BTREE
#define BTREE
#include <iostream>

template <typename T> class BinaryTree;
template <typename T> std::ostream& operator<<(std::ostream& out, const BinaryTree<T>& tree);

template<typename T>
class BinaryTree
{
public:
	BinaryTree() : root(nullptr) {}
	virtual T* add(T new_elem);
	virtual T* find(T elem);
	friend std::ostream& operator<< <T>(std::ostream out, const BinaryTree<T>& tree);

private:
	struct Node {
		Node* left, * right, * parent;
		T value;
		Node(T _value, Node* _parent);
	};
	Node* root;
	T* find_util(T elem, Node* node);
	void print_util(std::ostream& out, Node* node, int depth);
};

template<typename T>
inline BinaryTree<T>::Node::Node(T _value, Node* _parent)
{
	left = right = nullptr;
	parent = _parent;
	value = _value;
}

template<typename T>
inline T* BinaryTree<T>::add(T new_elem)
{
	Node* parent = nullptr, * it = root;
	while (it != nullptr) {
		if (it->value == new_elem)
			return it->value;
		parent = it;
		if (elem > it->value)
			it = it->right;
		else
			it = it->left;
	}

	it = new Node(new_elem, parent);

	if (parent != nullptr) {
		if (it->key > parent->key)
			parent->right = it;
		else
			parent->left = it;
	}
	else {
		root = it;
	}
	return it->value;
}

template<typename T>
inline T* BinaryTree<T>::find(T elem)
{
	return find_util(elem, root);
}

template<typename T>
inline T* BinaryTree<T>::find_util(T elem, Node* node)
{
	if (node == nullptr || node->value == elem)
		return node->value;
	if(elem > node->elem)
		find_util(elem, node->right);
	else
		find_util(elem, node->left);
}

template<typename T>
inline void BinaryTree<T>::print_util(std::ostream& out, Node* node, int depth)
{

}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, const BinaryTree<T>& tree)
{
	typename BinaryTree<T>::Node* root = tree.root;
	int depth = 0;
	


	return out;
}
















#endif // BTREE