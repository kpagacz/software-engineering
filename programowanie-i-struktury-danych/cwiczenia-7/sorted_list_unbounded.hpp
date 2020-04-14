#ifndef __SORTED_LIST
#define __SORTED_LIST

class List {
    private:
        class Node {
            friend class List;
            public:
                int _value;
                List::Node* _next;
                Node(): _value(0), _next(nullptr) {};
                Node(const int& value): _value(value), _next(nullptr) {};
        };
        List::Node* _head;
        List::Node* _tail;
        std::size_t _size;

    public:
        // constructors, destructor, assignment
        List(): _head(nullptr), _tail(nullptr), _size(0) {};
        List(const List&);
        List& operator=(const List&);
        List(List&&);
        List& operator=(List&&);
        ~List();

        // adding, removing
        void print() const;
        void insert(const int&);
        void remove(const int&);
        void remove_all_instances(const int&);

        // 
        std::size_t size() const;
        void clear();
        int at(const int&) const;

        // operators
        friend bool operator==(const List&, const List&);
        friend bool operator==(const List::Node&, const List::Node&);

};


#endif