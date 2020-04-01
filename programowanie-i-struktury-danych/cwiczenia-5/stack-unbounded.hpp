struct StackElement{
    int value;
    StackElement* next;

    StackElement(StackElement&);
    StackElement() = default;
};

class Stack{
    public:
        StackElement* first_element = nullptr;
        // constructors, destructors
        Stack() {};
        ~Stack();
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

};
