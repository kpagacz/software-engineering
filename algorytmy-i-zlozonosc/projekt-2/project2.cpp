#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>

#include "BinaryTree.h"
#include "SplayTree.h"
#include "Word.h"

std::vector<std::string> sequence_to_words(std::string& sequence) {
	for (auto& c : sequence) {
		if (c < 0 || c > 128)
			c = ' ';
	}
	for (auto c : { '"', '!', '?', '*', '.', ',', ';', '(', ')', '[', ']', ':' })
		sequence.erase(std::remove(sequence.begin(), sequence.end(), c), sequence.end());
	for (auto c : { "_", "--", "-" })
		while (sequence.find(c, 0) != std::string::npos)
			sequence.replace(sequence.find(c, 0), strlen(c), " ");

	std::vector<std::string> words;
	int delimiter = -1, last_begin = 0;
	do {
		last_begin = delimiter + 1;
		delimiter = sequence.find(' ', last_begin);
		words.push_back(sequence.substr(last_begin, delimiter - last_begin));
	} while (delimiter != std::string::npos);
	return words;
}

BinarySearchTree<Word>* read_novel(const std::string& file_name, BinarySearchTree<Word>* tree) {
	std::ifstream file(file_name, std::ios::in);
	std::string sequence;
	while (file >> sequence) {
		std::vector<std::string> words = sequence_to_words(sequence);

		for (const auto& word : words)
			if (word != "") {
				Word elem(word);
				if (tree != nullptr) {
					Word* found = tree->find(elem);
					if (found != nullptr)
						(*found)++;
					else
						tree->add(elem);
				}
			}
	}

	return tree;
}

std::vector<std::string> reservoir_sampling(const std::string& file_name, unsigned int sample_size = 100) {
	std::vector<std::string> random_words;
	std::ifstream file(file_name, std::ios::in);
	std::string sequence;

	// random generator setup
	std::mt19937 generator(7);
	unsigned int word_count = 0;

	while (file >> sequence) {
		std::vector<std::string> words = sequence_to_words(sequence);

		for (auto& word : words)
			if (word != "") {
				for (auto& c : word)
					c = std::tolower(c);

				if (random_words.size() < sample_size) {
					random_words.push_back(word);
				}
				else {
					std::uniform_int_distribution<int> distribution(0, word_count);
					unsigned int rand = distribution(generator);
					if (rand < sample_size)
						random_words[rand] = word;
				}
				word_count++;
			}
	}

	return random_words;
}

int main() {
	//BinarySearchTree<Word>* tree = new SplayTree<Word>;
	//read_novel("novels/1.txt", nullptr);
	//tree->flat_print();

	//std::vector<std::string> random_words = reservoir_sampling("novels/1.txt");
	//for (const auto& word : random_words)
	//	std::cout << word << "\n";

	BinarySearchTree<int> *tree = new SplayTree<int>;
	tree->add(1);
	tree->add(2);
	tree->add(3);
	tree->add(11);
	tree->add(5);
	tree->add(6);
	tree->add(20);
	tree->add(8);
	std::cout << *tree;
	std::cout << tree->height();
	

	//std::cout << tree.min() << "\n";
	//std::cout << *tree.find(4) << "\n";
	//std::cout << tree.find_next(7) << "\n";

	//Word w1(std::string("Hello1"));
	//std::cout << w1.get_word() << "\n";
	//Word w2("Hello2");
	//std::cout << w2.get_word() << "\n";
	//Word w3("a");
	//Word w4("b");

	//BinarySearchTree<Word> tree2;
	//tree2.add(w3);
	//tree2.add(w2);
	//tree2.add(w4);
	//tree2.add(w1);
	//std::cout << tree2;


	//SplayTree<int> splay;
	//splay.add(10);
	//std::cout << splay;
	//splay.add(7);
	//std::cout << splay;
	//splay.add(1);
	//std::cout << splay;
	//splay.add(3);
	//std::cout << splay;
	//splay.flat_print();
	//return 0;
}