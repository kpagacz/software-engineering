#ifndef AVL__
#define AVL__

#include <iostream>

template <typename T> class AVL;
template <typename T> std::ostream& operator<<(std::ostream& out, const AVL<T>& tree);

template <typename T>
class AVL{
public:
    AVL() : root(nullptr) {}
    ~AVL();

    T* add(const T&);
	T* find(const T&) const;
	void flat_print() const;
	int depth(const T&) const;

	// overloaded operators
	friend std::ostream& operator<< <T>(std::ostream& out, const AVL<T>& tree);
private:
    struct Node {
        Node* parent, *left, *right;
        T value;
        int balance;
        Node(const T& new_val, Node* _parent) : parent(_parent), value(new_val), balance(0) {}
    };

    Node* root;

    void print(std::ostream& out) const;

    void print_util(std::ostream& out, Node* node, int depth = 0, int depth_inc = 1) const;
    int depth_util(const T&, int, Node*) const;
    void delete_util(Node*);

    Node* find_node(const T&, Node*) const;
    Node* add_node(const T&);

    void rotate(Node*);
    void adjust_balance(Node*);
    void balance(Node*, Node*, Node*);
};

template <typename T>
AVL<T>::~AVL() {
    delete_util(root);
}

template <typename T>
void AVL<T>::delete_util(Node* node) {
    if(node != nullptr) {
        delete_util(node->left);
        delete_util(node->right);
        delete node;
    }
};

template <typename T>
void AVL<T>::print(std::ostream& out) const {
    print_util(out, root, 0, 1);
};

template <typename T>
void AVL<T>::print_util(std::ostream& out, Node* node, int depth, int depth_inc) const {
    if(node != nullptr) {
        print_util(out, node->right, depth + depth_inc, depth_inc);
        for(int i = 0; i < depth; i++) out << " ";
        out << node->value << "\n";
        print_util(out, node->left, depth + depth_inc, depth_inc);
    }
};

template <typename T>
void AVL<T>::flat_print() const {
    print_util(std::cout, root, 0, 0);
};

template <typename T>
T* AVL<T>::find(const T& elem) const {
    Node* found = find_node(elem, root);
    if(found == nullptr)
        return nullptr;
    else
        return &found->value;
};

template <typename T>
typename AVL<T>::Node* AVL<T>::find_node(const T& elem, Node* node) const {
    if(node == nullptr)
        return nullptr;

    if (node->value == elem)
        return node;

    if(elem > node->value)
        return find_node(elem, node->right);
    else
        return find_node(elem, node->left);
};

template<typename T>
int AVL<T>::depth(const T& val) const
{
	return depth_util(val, 0, root);
};

template<typename T>
int AVL<T>::depth_util(const T& val, int depth, Node* node) const
{
	if (node == nullptr) 
		throw std::runtime_error("value not found in the tree.");
	if (node->value == val)
		return depth;
	if (val > node->value)
		return depth_util(val, depth + 1, node->right);
	else
		return depth_util(val, depth + 1, node->left);
};

template <typename T>
void AVL<T>::rotate(Node* pivot) {
    if (root == pivot) return;
	Node* mover = nullptr;

	if (pivot == pivot->parent->right) {
		// left rotation

        pivot->parent->balance = pivot->parent->balance - 1 - std::max(pivot->balance, 0);
        pivot->balance = pivot->balance - 1 + std::min(pivot->parent->balance, 0);
		
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

        pivot->parent->balance = pivot->parent->balance + 1 - std::min(pivot->balance, 0);
        pivot->balance = pivot->balance + 1 - std::max(pivot->parent->balance, 0);

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
T* AVL<T>::add(const T& new_elem)
{
	Node* it = add_node(new_elem);
	return &it->value;
}

template<typename T>
typename AVL<T>::Node* AVL<T>::add_node(const T& new_elem)
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

    adjust_balance(it);

	return it;
}

template <typename T>
void AVL<T>::adjust_balance(Node* node) {
    Node* child = nullptr, *grandchild = nullptr;

    while(node != root) {
        if(node->parent->left == node) 
            node->parent->balance--;
        else
            node->parent->balance++;
        
        grandchild = child;
        child = node;
        node = node->parent;

        if(std::abs(node->balance) > 1) {
            balance(node, child, grandchild);
            break;
        }
    }
}

template <typename T>
void AVL<T>::balance(Node* node, Node* child, Node* grandchild) {
    if((node->left == child) == (child->left == grandchild)) {
        rotate(child);
    } else {
        rotate(child);
        rotate(grandchild);
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const AVL<T>& tree) {
    tree.print(out);
    out << "\n";
    return out;
};

#endif // AVL__