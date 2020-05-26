#ifndef _SORTED_LIST
#define _SORTED_LIST

#include<iostream>

template <typename T>
class SortedList {
    private:
        struct Node {
            T element;
            Node* next;
            Node(const T& _el): element(_el), next(nullptr) {};
        };
        std::size_t size;
        Node* head;
        /*
            Abstract data type - generic sorted linked list.
            Valid state:
                size is the number of nodes in the list (at least 0, 0 when empty)
                head is a pointer to the first node of the list or nullptr if the list is empty
                Nodes of the list are sorted in an increasing order using operator > of class T
                next of Node points to the next node in the list
                next of the last node is nullptr
            Assumes:
                class T has operators > and ==
        */

       void removeNode(SortedList<T>::Node* &pred, SortedList<T>::Node* &succ);
       void deleteChain(SortedList<T>::Node*&, SortedList<T>::Node*&, SortedList<T>::Node*&, SortedList<T>::Node*&);

    public:
        // constructors, destructors, assignment
        SortedList(): size(0), head(nullptr) {};
        // SortedList(const &SortedList);
        // SortedList(&&SortedList);
        // SortedList& operator=(const &SortedList);
        // SortedList& operator=(&&SortedList);
        ~SortedList();

        // insertion
        void insertNode(T element);
            // Inserts node in the list with the element of class T element.
            // arguments:
            //  element is an instance of class T to be added to the list
            // Pre state: valid state
            // Post state: valid state, size of the list is increased by one,
            //  there is another node in the list with the value of the element.
            // Exceptions: None

        // popping
        void deleteNode(const T &value);
            /* Deletes the node in the list with the element of value.
            Arguments:
                value: value of the Node to be deleted

            Pre state: 
                valid state

            Post state: valid state, if the element of value exists in the list:
                size of the list is decreased by one,
                the node with the element value is deleted.

            Exceptions:
                None
            */

        // everything else
        void empty();
            /* Empties the list.
            Pre state:
                valid state
            Post state:
                valid state, list has size 0 and head is nullptr 
            */
        
        friend std::ostream& operator<<(std::ostream& output_stream, const SortedList<T>& list) {
            /* Prints the list to the out_stream
            Pre state:
                valid state
            Post state:
                valid state
            */
            output_stream << "SortedList: " << list.head << std::endl;
            SortedList<T>::Node *it = list.head;
            while(it != nullptr) {
                output_stream << it->element << " "; 
                it = it->next;
            }
            output_stream << std::endl;
            return output_stream;
        };

        void removeEveryNth(int N);
            /* Removes every Nth element of the list starting from the Nth element
            Arguments:
                N - integer larger than 0

            Pre state:
                valid state
            
            Post state:
                valid state, each Nth Node is removed from the list, size is
                    diminished by floor of the original size divided by N
            */

        void removeDuplicated();
            /* Removes Nodes with duplicate elements.
            Pre state:
                valid state

            Post state:
                valid state, each element in the list is unique,
                size is diminished by number of duplicated elements
            */
};

#include "sorted-list-generic.cpp"

#endif