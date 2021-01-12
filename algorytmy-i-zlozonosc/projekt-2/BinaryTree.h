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
	virtual T* add(const T& new_elem);
	virtual T* find(const T&) const;
	virtual T min() const;
	virtual T find_next(T value);
	void flat_print() const;

	// overloaded operators
	friend std::ostream& operator<< <T>(std::ostream& out, const BinarySearchTree<T>& tree);

protected:
	struct Node {
		Node* left, * right, * parent;
		T value;
		Node(T _value, Node* _parent);
	};
	Node* root;

	// rotation
	void rotate(Node*);

	// finding nodes
	Node* find_node(T, Node*) const; // find value

	// adding nodes
	Node* add_node(const T&);
private:
	// printing recursive methods
	void print_util(std::ostream& out, Node* node, int depth, int depth_inc = 1) const;
	void print(std::ostream&) const;
	void flat_print_util(Node*) const;

	// destructor recursive method
	void delete_util(Node* node);

	// finding successor
	Node* find_succ(Node*) const; // find successor
	Node* min(Node*) const; // find minimum
};

template<typename T>
inline BinarySearchTree<T>::Node::Node(T _value, Node* _parent)
{
	left = right = nullptr;
	parent = _parent;
	value = _value;
}

template<typename T>
inline T* BinarySearchTree<T>::add(const T& new_elem)
{
	Node* it = add_node(new_elem);
	return &it->value;
}

template<typename T>
inline T* BinarySearchTree<T>::find(const T& elem) const
{
	Node* found = find_node(elem, root);
	if (found)
		return &found->value;
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
	Node* found = find_node(value, root);
	if (!found)
		throw std::runtime_error("Value not found in the tree");
	Node* successor = find_succ(found);
	if (!successor)
		throw std::runtime_error("Successor not found in the tree");
	return successor->value;
}

template<typename T>
inline void BinarySearchTree<T>::flat_print() const
{
	flat_print_util(root);
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
inline typename BinarySearchTree<T>::Node* BinarySearchTree<T>::find_node(T elem, Node* node) const
{
	if (node == nullptr)
		return nullptr;
	if (node->value == elem)
		return node;
	if(elem > node->value)
		return find_node(elem, node->right);
	else
		return find_node(elem, node->left);
}

template<typename T>
inline typename BinarySearchTree<T>::Node* BinarySearchTree<T>::add_node(const T& new_elem)
{
	Node* parent = nullptr, * it = root;
	while (it != nullptr) {
		if (it->value == new_elem)
			return it;
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

	return it;
}

template<typename T>
inline void BinarySearchTree<T>::print_util(std::ostream& out, Node* node, int depth, int depth_inc) const
{
	if (node) {
		print_util(out, node->right, depth + depth_inc, depth_inc);
		for (int i = 0; i < depth; i++)
			out << "  ";
		out << node->value << "\n";
		print_util(out, node->left, depth + depth_inc, depth_inc);
	}
}

template<typename T>
inline void BinarySearchTree<T>::print(std::ostream& out) const
{
	int depth = 0;
	print_util(out, root, depth);
}

template<typename T>
inline void BinarySearchTree<T>::flat_print_util(Node* node) const
{
	if (node) {
		flat_print_util(node->left);
		std::cout << node->value << "\n";
		flat_print_util(node->right);
	}
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
inline void BinarySearchTree<T>::rotate(Node* pivot)
{
	if (root == pivot) return;
	Node* mover = nullptr;

	if (pivot == pivot->parent->right) {
		// left rotation
		
		mover = pivot->left;
		pivot->left = pivot->parent;
		pivot->parent = pivot->left->parent;
		if (pivot->left->parent) {
			if (pivot->left->parent->left == pivot->left)
				pivot->left->parent->left = pivot;
			else
				pivot->left->parent->right = pivot;
		}
		pivot->left->parent = pivot;
		pivot->left->right = mover;
		if(mover) mover->parent = pivot->left;
	}
	else {
		// right rotation

		mover = pivot->right;
		pivot->right = pivot->parent;
		pivot->parent = pivot->right->parent;
		if (pivot->right->parent) {
			if (pivot->right->parent->left == pivot->right)
				pivot->right->parent->left = pivot;
			else
				pivot->right->parent->right = pivot;
		}
		pivot->right->parent = pivot;
		pivot->right->left = mover;
		if(mover) mover->parent = pivot->right;
	}
	if (pivot->parent == nullptr)
		root = pivot;
}

template<typename T>
inline typename BinarySearchTree<T>::Node* BinarySearchTree<T>::min(Node* node) const
{
	if (!node)	// case: root is null
		return nullptr;
	if (!node->left && !node->right)
		return node;
	if (node->left)
		return min(node->left);
	else
		return min(node->right);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const BinarySearchTree<T>& tree)
{
	tree.print(out);

	return out;
}

#endif // BTREE
