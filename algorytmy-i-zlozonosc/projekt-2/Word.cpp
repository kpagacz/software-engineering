#include "Word.h"

Word::Word(const std::string& _string)
{
    count = 1;
    word = _string;
    for (auto& c : word)
        c = std::tolower(c);
}

Word::Word(const char* sequence)
{
    count = 1;
    word = std::string(sequence);
    for (auto& c : word)
        c = std::tolower(c);
}

std::string Word::get_word() const
{
    return word;
}

void Word::set_word(const std::string& new_word)
{
    word = new_word;
}

bool Word::operator==(const Word& other)
{
    return word.compare(other.get_word()) == 0;
}

bool Word::operator!=(const Word& other)
{
    return !(*this == other);
}

bool Word::operator>(const Word& other)
{
    return word.compare(other.get_word()) > 0;
}

bool Word::operator>=(const Word& other)
{
    return word.compare(other.get_word()) >= 0;
}

bool Word::operator<(const Word& other)
{
    return !(*this >= other);
}

bool Word::operator<=(const Word& other)
{
    return !(*this > other);
}

Word& Word::operator+(int value)
{
    count += value;
    return *this;
}

Word& Word::operator++()
{
    count++;
    return *this;
}

Word Word::operator++(int)
{
    Word copy(*this);
    operator++();
    return copy;
}

Word& Word::operator--()
{
    count--;
    return *this;
}

Word Word::operator--(int)
{
    Word copy(*this);
    operator--();
    return copy;
}

std::ostream& operator<<(std::ostream& out, const Word& word)
{
    out << word.get_word();
    return out;
}
