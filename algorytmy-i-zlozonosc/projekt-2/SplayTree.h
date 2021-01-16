#ifndef SPLAY__
#define SPLAY__

#include "BinaryTree.h"

template<typename T>
class SplayTree :
    public BinarySearchTree<T>
{
public:
    SplayTree() : BinarySearchTree<T>() {}
    ~SplayTree() = default;
    T* add(const T&);
    T* find(const T&);

private:
    typedef typename BinarySearchTree<T>::Node Node;
    void splay(Node*);
};


template<typename T>
inline T* SplayTree<T>::add(const T& elem)
{
    Node* added = this->add_node(elem);
    splay(added);
    return &added->value;
}

template<typename T>
inline T* SplayTree<T>::find(const T& elem)
{
    Node* found = this->find_node(elem, this->root);
    if (found != nullptr) {
        splay(found);
        return &found->value;
    }
    else
        return nullptr;
}

template<typename T>
inline void SplayTree<T>::splay(Node* node)
{
    while (node != this->root) {
        if (node->parent == this->root) {
            this->rotate(node);
            return;
        }

        Node* gp = node->parent->parent, * parent = node->parent;
        if ((node == parent->left) == (parent == gp->left)) {
            this->rotate(parent);
            this->rotate(node);
        }
        else {
            this->rotate(node);
            this->rotate(node);
        }
    }
}


#endif // SPLAY__
