#ifndef BTREE
#define BTREE
#include <iostream>
#include <stdexcept>

template <typename T> class BinarySearchTree;
template <typename T> std::ostream& operator<<(std::ostream& out, const BinarySearchTree<T>& tree);

template<typename T>
class BinarySearchTree
{
public:
	// constructors, destructors, assignment
	BinarySearchTree() : root(nullptr) {}
	virtual ~BinarySearchTree();

	// other methods
	virtual T* add(T new_elem);
	friend std::ostream& operator<< <T>(std::ostream& out, const BinarySearchTree<T>& tree);
	T* find(const T&) const;
	T min() const;
	T find_next(T value);

private:
	struct Node {
		Node* left, * right, * parent;
		T value;
		Node(T _value, Node* _parent);
	};
	Node* root;

	// printing recursive methods
	void print_util(std::ostream& out, Node* node, int depth) const;
	void print(std::ostream&) const;

	// destructor recursive method
	void delete_util(Node* node);

	// finding nodes
	virtual Node* find(T, Node*) const; // find value
	virtual Node* min(Node*) const; // find minimum
	virtual Node* find_succ(Node*) const; // find successor
};

template<typename T>
inline BinarySearchTree<T>::Node::Node(T _value, Node* _parent)
{
	left = right = nullptr;
	parent = _parent;
	value = _value;
}

template<typename T>
inline T* BinarySearchTree<T>::add(T new_elem)
{
	Node* parent = nullptr, * it = root;
	while (it != nullptr) {
		if (it->value == new_elem)
			return &it->value;
		parent = it;
		if (new_elem > it->value)
			it = it->right;
		else
			it = it->left;
	}

	it = new Node(new_elem, parent);

	if (parent != nullptr) {
		if (it->value > parent->value)
			parent->right = it;
		else
			parent->left = it;
	}
	else {
		root = it;
	}
	return &it->value;
}

template<typename T>
inline T* BinarySearchTree<T>::find(const T& elem) const
{
	T* found = &find(elem, root)->value;
	if (found)
		return found;
	else
		return nullptr;
}

template<typename T>
inline T BinarySearchTree<T>::min() const
{
	if (root == nullptr)
		throw std::out_of_range("Tree is empty");
	return min(root)->value;
}

template<typename T>
inline T BinarySearchTree<T>::find_next(T value)
{
	Node* found = find(value, root);
	if (!found)
		throw std::runtime_error("Value not found in the tree");
	Node* successor = find_succ(found);
	if (!successor)
		throw std::runtime_error("Successor not found in the tree");
	return successor->value;
}

template<typename T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
	if (root) {
		delete_util(root->right);
		delete_util(root->left);
		delete root;
	}
}

template<typename T>
inline typename BinarySearchTree<T>::Node* BinarySearchTree<T>::find(T elem, Node* node) const
{
	if (node == nullptr)
		return nullptr;
	if (node->value == elem)
		return node;
	if(elem > node->value)
		find(elem, node->right);
	else
		find(elem, node->left);
}

template<typename T>
inline void BinarySearchTree<T>::print_util(std::ostream& out, Node* node, int depth) const
{
	if (node) {
		print_util(out, node->right, depth + 1);
		for (int i = 0; i < depth; i++)
			out << "  ";
		out << node->value << "\n";
		print_util(out, node->left, depth + 1);
	}
}

template<typename T>
inline void BinarySearchTree<T>::print(std::ostream& out) const
{
	int depth = 0;
	print_util(out, root, depth);
}

template<typename T>
inline void BinarySearchTree<T>::delete_util(Node* node)
{
	if (node) {
		delete_util(node->left);
		delete_util(node->right);
		delete node;
	}
}

template<typename T>
inline typename::BinarySearchTree<T>::Node* BinarySearchTree<T>::find_succ(Node* node) const
{
	if (node->right)
		return min(node->right);

	Node* it = node;
	while (it->parent && it->parent->right == it) it = it->parent;
	return it->parent;
}

template<typename T>
inline typename BinarySearchTree<T>::Node* BinarySearchTree<T>::min(Node* node) const
{
	if (!node)	// case: root is null
		return nullptr;
	if (!node->left && !node->right)
		return node;
	if (node->left)
		min(node->left);
	else
		min(node->right);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const BinarySearchTree<T>& tree)
{
	tree.print(out);

	return out;
}

#endif // BTREE
