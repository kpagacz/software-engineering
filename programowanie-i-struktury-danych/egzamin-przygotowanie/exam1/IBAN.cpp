#include "IBAN.h"

IBAN::IBAN(const std::string& new_value)
{
    iban = "";
    set_iban(new_value);
}

std::string IBAN::get_iban() const
{
    return iban;
}

void IBAN::set_iban(const std::string& new_iban)
{
    iban = new_iban;
}

bool IBAN::operator<(const IBAN& other) const
{   
    std::string other_iban = other.get_iban();
    int comparison = iban.compare(other_iban);
    return comparison == -1;
}

std::ostream& operator<<(std::ostream& out, const IBAN& iban) 
{
    out << iban.iban;
    return out;
}
