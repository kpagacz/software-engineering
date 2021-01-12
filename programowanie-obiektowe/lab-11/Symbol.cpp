#include "Symbol.h"

std::ostream& operator<<(std::ostream& out, const Symbol& symbol)
{
    symbol.print(out);
    return out;
}

void Kolko::print(std::ostream& out) const
{
    out << 'o';
}

void Krzyzyk::print(std::ostream& out) const
{
    out << 'x';
}
