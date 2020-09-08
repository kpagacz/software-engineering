#include"Header.h"
int main()
{
	sznur s1; 
	for (int i : {3, 6, 6, 4, 7, 5, 7, 3, 2, 9, 7, 7, 4, 2 })
		s1.wstaw(i);
		cout << "wasz sznur: "; 
	s1.wypisz(); 


	// (przykład: dla M=2 sznur 4, 7,5,1, 6, 6,7,1,4,2,9,1,1 uzyska postać 1, 1, 2, 1, 1, a dla M = 3 ten sam sznur zostanie zredukowany do postaci 4, 1, 1, 4, 2, 1, 1).
/*	cout << "funk usun: "; 
	s1.usun(3); 
	s1.wypisz(); */


	//Przykład: sznur 3, 6, 6, 4, 7, 5, 7, 3, 2, 9, 7, 7, 4, 2 ma zostać przekształcony do postaci 3, 6, 6, 9, 7, 7, 4, 2, 5, 7, 4, 2, 3, 7
	cout << "funk przeniesTrojki: "; 
	s1.przeniesTrojki(); 
	s1.wypisz();

	return 0;
}