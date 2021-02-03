#include <iostream>

struct Node {
	Node* left, * right;
	int value;
	Node(int _value = 0) : left(nullptr), right(nullptr), value(_value) {}
};

void compress(Node* root, int count);

void DSW(Node*& root) {
	// make a pseudo-root
	Node* pseudo_root = new Node;
	pseudo_root->right = root;

	// tree-to-vine
	Node* tail = pseudo_root;
	Node* rest = pseudo_root->right;
	int size = -1;

	while (rest != nullptr) {
		if (rest->left == nullptr) {
			tail = rest;
			rest = rest->right;
		}
		else {
			Node* temp = rest->left;
			rest->left = temp->right;
			temp->right = rest;
			rest = temp;
			tail->right = temp;
		}
		size++;
	}

	// vine-to-tree
	int leaves = size + 1 - pow(2, int(log2(size + 1)));
	std::cout << "LEAVES: " << leaves << '\n';
	compress(pseudo_root, leaves);
	size = size - leaves;
	while (size > 1) {
		compress(pseudo_root, size / 2);
		size = size / 2;
	}

	root = pseudo_root->right;
	delete pseudo_root;
}

void compress(Node* root, int count) {
	Node* scanner = root;
	for (int i = 1; i < count; i++) {
		Node* child = scanner->right;
		scanner->right = child->right;
		scanner = scanner->right;
		child->right = scanner->left;
		scanner->left = child;
	}
}


void print_tree(Node* root, int depth = 0) {
	if (root != nullptr) {
		print_tree(root->right, depth + 1);
		for (int i = 0; i < depth; i++) std::cout << " ";
		std::cout << root->value << '\n';
		print_tree(root->left, depth + 1);
	}
}

int main() {
	Node* root = new Node;
	root->value = 11;
	root->left = new Node(10);
	root->left->left = new Node(7);
	root->left->left->left = new Node(3);

	print_tree(root);
	DSW(root);
	print_tree(root);

	return 0;
}