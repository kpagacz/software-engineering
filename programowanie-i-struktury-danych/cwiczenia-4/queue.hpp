class Queue {
    private:
        int* _queue;
        int first_index;
        int current_size;
        int max_size;
    public:
        // basic operatotions
        Queue();
        Queue(const Queue&) = delete; // copying constructor
        Queue(Queue&&) = delete; // move constructor
        Queue& operator=(const Queue&) = delete; // copy assignment
        Queue& operator=(const Queue&&) = delete; // move assignment
        ~Queue();

        void Output() const;
        void Enqueue(const int& element);
        int Dequeue();
        void Clear();
        int Size() const;
};