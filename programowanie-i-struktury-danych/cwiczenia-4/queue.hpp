class Queue {
    private:
        int* _queue;
        int first_index;
        int current_size;
        int max_size;
    public:
        // basic operatotions
        Queue();
        Queue(const Queue&); // copying constructor
        Queue& operator=(Queue); // copy assignment
        ~Queue();

        void Output() const;
        void Enqueue(const int& element);
        int Dequeue();
        void Clear();
        int Size() const;
};