struct Node{
    int _value;
    Node* _next_node; 
    Node() : _value(0), _next_node(nullptr) {};
    Node(int value) : _value(value), _next_node(nullptr) {};
    friend bool operator==(const Node& lhs, const Node& rhs);
    friend bool operator!=(const Node& lhs, const Node& rhs);
};

class Queue{
    private:
        Node* _head;
        Node* _tail;
        std::size_t _size;

    public:
        // CONSTRUCTORS DESTRUCTORS ASSIGNMENT
        Queue() : _head(nullptr), _tail(nullptr), _size(0) {};
        ~Queue();
        Queue (Queue& other_queue);
        Queue& operator=(Queue& other_queue); // basic exception guarantee only
        Queue(Queue&&);
        Queue& operator=(Queue&&); // basic exception guarantee only

        // SETTERS GETTERS
        std::size_t size() const;

        // OPERATORS
        friend bool operator==(const Queue& lhs, const Queue& rhs);

        // QUEUE DEQUEUE ELEMENTS
        void enqueue(const int& value);
        int dequeue();

        // OTHER
        void print() const;
        void clear();
        
};