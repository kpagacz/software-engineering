#include <iostream>
#include "Header.h"


int main() {
    sznur s1;
    for (int i : {1,2,3}) {
        s1.wstaw(i);
    }
    
    std::cout << "Sznur:";
    s1.wypisz();
    // sznur ma head oraz tail:
    s1.wypiszHead();
    s1.wypiszTail();

    s1.usun(2); // usun() bedzie dzialal dobrze
    std::cout << "Sznur po metodzie usun:";
    s1.wypisz();

    // zobaczmy, jak wyglada head i tail sznura po metodzie usun
    // head nie powinien sie zmienic
    // tail powinien wskazywac na wezel z value 2
    // innymi slowy:
    // bylo tak: 1->2->3->
    //      head ^     ^ tail
    // a po usun powinno byc tak:
    //          1->2->
    //     head ^  ^ tail
    s1.wypiszHead(); // head jest w porzadku
    s1.wypiszTail(); // adres tail jest taki jak byl! i wartosc nie jest dwa!
    // co sie stalo?
    // metoda usun() zwolnila pamiec wezla z wartoscia 3, a tail nie zmienil adresu
    // stad value wezla, na ktory wskazuje tail jest losowa!
    // jak temu zapobiec?
    // trzeba sprawdzac, czy nie usuwa sie taila, i jesli sie to robi, to zmieniac wezel
    // na ktory tail wskazuje - zrobilem te zmiany w funkcji sznur::nowy_usun()

    // przetestujmy nowy_usun
    std::cout << "To samo co wyzej, tylko uzywajac nowy_usun():\n";
    sznur s2;
    for (int i : {1,2,3}) {
        s2.wstaw(i);
    }
    s2.wypisz();
    s2.nowy_usun(2);
    s2.wypisz();
    s2.wypiszHead(); // head sie zgadza
    s2.wypiszTail(); // i tail tez sie zgadza!
    return 0;
}