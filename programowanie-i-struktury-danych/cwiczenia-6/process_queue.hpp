struct Process {
    unsigned int _threads;
    unsigned int _PID;
    Process() : _threads(0), _PID(0) {};
    Process(const unsigned int& __threads, const unsigned int& __PID) :
        _threads(__threads),
        _PID(__PID)
        {};
    Process(const unsigned int& __PID) : _PID(__PID), _threads(1) {};
    
    friend bool operator==(const Process& lhs, const Process& rhs);
    friend bool operator!=(const Process& lhs, const Process& rhs);
};

struct Node {
    Process _process;
    Node* _next_node;

    Node() : _process(Process()), _next_node(nullptr) {};
    Node(const Process& __process) : _process(__process), _next_node(nullptr) {};

    friend bool operator==(const Node& lhs, const Node& rhs);
    friend bool operator!=(const Node& lhs, const Node& rhs);
};

class ProcessQueue {
    private:
        Node* _head;
        Node* _tail;
        std::size_t _size;

    public:
        // constructors destructors assignment
        ProcessQueue() : _head(nullptr), _tail(nullptr), _size(0) {};
        ~ProcessQueue();

        // other
        void print() const;
        Node* findProcess(const unsigned int& PID) const;
        void addProcess(const unsigned int& PID, const unsigned int& threads = 1);
        void prioritizeProcess(const unsigned int& PID);
};