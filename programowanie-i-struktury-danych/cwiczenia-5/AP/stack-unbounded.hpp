///AP: lepiej byloby zdefiniowac StackElement w prywatnej czesci Stack -
/// - powinnismy traktowac programiste piszacego biblioteke i programiste uzywajacego jej jako dwie rozne osoby,
///  piszacy biblioteke powinien zrobic ja maksymalnie bezpieczna tzn nie dac uzytkownikom mozliwosci wykonania dzialan "nielegalnych"
///   obecnie w main  mozna swobodnie ingerowac w zawartosc wezlow, tworzyc wezly itd  -
/// - czyli biblioteka Stos nie zapewni ze budowana struktura musi byc obslugiwana jak stos

#include<iostream>


struct StackElement{
    int value;
    StackElement* next;   ///AP: warto byloby przypisac nullptr - "smieciowe" nastepniki nie sa zbyt bezpieczne

    StackElement(StackElement&);   /// AP: bardziej przydalby sie "zwykly" konstruktor pozwalajacy wpisac do wezla wartosci przekazane przez parametry
                                   ///     bo taka operacja jest potrzebna czesto, natomiast kopiowanie calosci wezla raczej rzadko
                                   ///     (przewaznie jesli tworzymy "kopie" wezla to potrzebna nam kopia wartosci, nastepnik bedzie inny)
    StackElement() = default;
};

class Stack{


    public:
       StackElement* first_element = nullptr;  ///AP: to pole powinno byc prywatne,
                                                /// jesli nie jest, to w main mozna zmienic zawartosc stosu w dowolny sposob, niekoniecznie odpowiadajacy definicji stosu
        // constructors, destructors
        Stack() { std::cout << "KONSTRUKTOR () tworzy " << this << " \n";};  //AP: dopisane w celach demonstracyjnych
        ~Stack();

        /// AP: przydaloby sie const przy parametrach metod kopiujacych (i innych nie zmieniajacych parametru)
        Stack(Stack&); // copy constructor
        Stack(Stack&&); // move constructor
        // operators
        Stack& operator=(Stack&); // copy assignment
        Stack& operator=(Stack&&); // move assignment
        friend bool operator==(Stack&, Stack&);

        void print();
        void push(const int&);
        int pop();
        int size();
        void clear();

        Stack costam() const;   ///AP: dopisane przeze mnie w celach demonstracyjnych

};
