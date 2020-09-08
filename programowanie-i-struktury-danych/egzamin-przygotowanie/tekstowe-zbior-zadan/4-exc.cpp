// W pliku "secret.msg" przechowywana jest zaszyfrowana wiadomość. Do zaszyfrowania tekstu użyto tablicy postaci:

// litera kodu (przyklad):	guwyrmqpsaeicbnozlfhdkjxtv 
// litera oryginalna:	abcdefghijklmnopqrstuvwxyz

// Napisz program tłumaczący zaszyfrowaną wiadomość na zwykły język i wypisujący ją na ekranie, a opcjonalnie zapisujący ją do pliku. 
// Kod szyfru - pierwsza linia w przykładzie powyżej - powinna być wprowadzana z klawiatury. 

#include<string>
#include<iostream>
#include<fstream>
#include<stdexcept>

int main() {
    std::string code;
    std::cout << "Input code: ";
    std::cin >> code;

    std::ifstream msg;
    std::string secret_message_file_name = "4-secret.msg";
    msg.open(secret_message_file_name, std::ios::out);

    if(msg.is_open()) {
        char c;

        std::string output_name = "4-out.txt";
        std::ofstream output;
        output.open(output_name, std::ios::in | std::ios::trunc);
        if(!output.is_open()) {
            throw std::runtime_error("Could not open output file");
        }

        while(msg.get(c)) {
            if(isalpha(c)) {
                int position = code.find(c);
                c = 'a' + position;
            }
            std::cout << c;
            output << c;
        }

        output.close();
    } else {
        throw std::runtime_error("Could not open secret message file");
    }

    msg.close();
        return 0;
}