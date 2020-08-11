class Sznur {
    private:
        struct Node {
            Node(): value(0), next(nullptr) {};
            Node(const int& new_el): value(new_el), next(nullptr) {};
            Node* next;
            int value;
        };

        Node* head;
        size_t size;
		void move_between(Node*, Node*, Node*);

    public:
        // constructors destructors
        Sznur(): head(nullptr), size(0) {};
        ~Sznur();

        void print() const;
        void insert(const int&);
        void removeFragments(const int& P);
		void move();
};