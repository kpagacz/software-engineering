class Stack {
    private:
        int* _stack;
        int max_size;
        int current_size;
    public:
        Stack(const int& size);
        ~Stack();
        Stack(const Stack&) = delete; // copy constructor
        Stack(Stack&&) = delete; // move constructor
        Stack& operator=(const Stack&) = delete; // copy assignment
        Stack& operator=(Stack&&) = delete; // move assignment
        void Output() const;
        void Push(const int& element);
        int Pop();
        void Clear();
        int Size() const;
};