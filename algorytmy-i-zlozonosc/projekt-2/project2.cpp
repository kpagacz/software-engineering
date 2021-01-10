#include <iostream>

#include "BinaryTree.h"
#include "Word.h"

int main() {
	BinarySearchTree<int> tree;

	tree.add(7);
	tree.add(10);
	tree.add(3);
	tree.add(1);
	tree.add(4);
	std::cout << tree;
	std::cout << tree.min() << "\n";
	std::cout << *tree.find(4) << "\n";
	std::cout << tree.find_next(7) << "\n";

	Word w1(std::string("Hello1"));
	std::cout << w1.get_word() << "\n";
	Word w2("Hello2");
	std::cout << w2.get_word() << "\n";

	Word w3("a");
	Word w4("b");
	BinarySearchTree<Word> tree2;
	tree2.add(w3);
	tree2.add(w2);
	tree2.add(w4);
	tree2.add(w1);
	std::cout << tree2 << "\n";
	return 0;
}