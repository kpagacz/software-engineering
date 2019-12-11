# include <iostream>
using namespace std ;
int licznik ; // zmienna globalna
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void pierwsza_funkcja () ;
void druga_funkcja () ;
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int main ()
{
pierwsza_funkcja () ; pierwsza_funkcja () ; pierwsza_funkcja () ;
druga_funkcja () ; druga_funkcja () ;
pierwsza_funkcja () ;
cout << " licznik globalny : " << licznik << "\n";
return 0;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void pierwsza_funkcja ()
{
static int licznik ; // automatyczne zerowanie
licznik = licznik + 1;
cout << " pierwsza_funkcja wykonana " << licznik << " raz \n";
}
void druga_funkcja ()
{
static int licznik = 100; // aby rozroznic liczniki
licznik = licznik + 1;
cout << " druga_funkcja wykonana " << licznik << " raz \n";
}