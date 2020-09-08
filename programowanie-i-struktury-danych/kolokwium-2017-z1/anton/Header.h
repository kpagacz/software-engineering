#ifndef bib_h
#define bib_h
#include<iostream>
using namespace std; 

struct sznur
{
private:
	struct box
	{
		int value; 
		box* next = nullptr;
		box(int a, box* b = nullptr)
		{
			value = a; 
			next = b; 
		}
	};
	box* head = nullptr; 
	box* tail = nullptr;
	int counter = 0; 
public: 
	void wypiszHead();
	void wypiszTail();
	void wypisz(); 
	void wstaw(int a); 
	void usun(int m); 
	void nowy_usun(int m);
	void przeniesTrojki(); 


};


#endif // !1
