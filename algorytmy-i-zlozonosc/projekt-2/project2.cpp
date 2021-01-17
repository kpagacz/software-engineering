#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>

#include "BinaryTree.h"
#include "SplayTree.h"
#include "AVL.h"
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

AVL<Word>* read_novel_avl(const std::string& file_name, AVL<Word>* tree) {
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

void analyzeNovel(const std::string& novel, std::ofstream& out_file) {
	BinarySearchTree<Word>* bst = new BinarySearchTree<Word>;
	BinarySearchTree<Word>* splay = new SplayTree<Word>;
	AVL<Word>* avl = new AVL<Word>;

	// Output
	std::cout << "Novel: " << novel << '\n';

	// measure time of loading data into trees
	std::clock_t s_clock, e_clock;
	s_clock = std::clock();
	read_novel(novel, bst);
	e_clock = std::clock();
	std::cout << "Populating a BST took: " << std::setprecision(6) << std::fixed << ((double)(e_clock) - (double)(s_clock)) / CLOCKS_PER_SEC << " seconds\n";

	s_clock = std::clock();
	read_novel(novel, splay);
	e_clock = std::clock();
	std::cout << "Populating a splay tree took: " << std::setprecision(6) << std::fixed << ((double)(e_clock) - (double)(s_clock)) / CLOCKS_PER_SEC << " seconds\n";

	// s_clock = std::clock();
	// read_novel(novel, avl);
	// e_clock = std::clock();
	// std::cout << "Populating an AVL tree took: " << std::setprecision(6) << std::fixed << ((double)(e_clock) - (double)(s_clock)) / CLOCKS_PER_SEC << " seconds\n";

	// choosing words to find
	std::vector<std::string> sampled_words = reservoir_sampling(novel);
	
	// finding
	for(const auto& word : sampled_words) {
		int occurences = bst->find(word)->get_count();
		out_file << "BST," << novel << "," << word << "," << bst->depth(word) << "," << occurences << "\n";
		out_file << "Splay," << novel << "," << word << "," << splay->depth(word) << "," << occurences << "\n";
		splay->find(word);
	}
}

int main() {
	// std::vector<std::string> novels {
	// 	std::string("novels/1.txt"),
	// 	std::string("novels/2.txt"),
	// 	std::string("novels/3.txt"),
	// 	std::string("novels/4.txt"),
	// 	std::string("novels/5.txt"),
	// };

	// std::ofstream results_file;
	// results_file.open("results.csv");
	// for(const auto& novel : novels) {
	// 	analyzeNovel(novel, results_file);
	// }
	// results_file.close();

	AVL<Word>* tree = new AVL<Word>;
	read_novel_avl("novels/1.txt", tree);
	tree->flat_print();

	// AVL<Word>* tree = new AVL<Word>;
	// Word w1("a");
	// Word w2("christmas");
	// Word w3("carol");
	// tree->add(w1);
	// std::cout << *tree;
	// tree->add(w2);
	// std::cout << *tree;
	// tree->add(w3);
	// std::cout << *tree;

	// AVL<int> * tree = new AVL<int>;
	// for(int i = 0; i < 100; i++)
	// 	tree->add(i);
	// std::cout << *tree;

	return 0;
}