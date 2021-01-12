#ifndef WORD__
#define WORD__

#include <iostream>
#include <string>
class Word
{
public:
	Word(const std::string& _string);
	Word(const char* sequence = "");
	~Word() = default;

	// getters, setters
	std::string get_word() const;
	void set_word(const std::string&);

	// relational operators
	bool operator==(const Word& other) const;
	bool operator!=(const Word& other) const;
	bool operator>(const Word& other) const;
	bool operator>=(const Word& other) const;
	bool operator<(const Word& other) const;
	bool operator<=(const Word& other) const;

	// arithmetic operators
	Word& operator+(int);
	Word& operator++();
	Word operator++(int);
	Word& operator--();
	Word operator--(int);

	// printing
	friend std::ostream& operator<<(std::ostream&, const Word&);

private:
	std::string word;
	int count;
};

#endif // WORD__
