#include <iostream>
#include <cmath>


struct node
{
    int key;

    node* left;
    node* right;
};


node* Add(node*& r, int number)
{
    if (!r)
    {
        r = new node;
        r->key = number;
        r->left = r->right = nullptr;  // nowy węzeł zawsze jest liściem
        return r;
    }

    if (number > r->key) return Add(r->right, number);

    return Add(r->left, number);
}

node* Add2(node*& r, int number)
{
    if (!r)
    {
        r = new node;
        r->key = number;
        r->left = r->right = nullptr;  // nowy węzeł zawsze jest liściem
        return r;
    }

    if (r->key == number)
        return r;

    if (number > r->key) return Add2(r->right, number);

    return Add2(r->left, number);
}

node* Add_Seq(node*& r, int number)
{
    if (r == nullptr) {
        r = new node;
        r->key = number;
        r->left = r->right = nullptr;
        return r;
    }

    node* child = r, * parent = nullptr;
    while (child != nullptr) {
        if (child->key == number)
            return child;
        if (number > child->key) {
            parent = child;
            child = child->right;
        }
        else {
            parent = child;
            child = child->left;
        }
    }

    child = new node;
    child->key = number;
    child->left = child->right = nullptr;  // nowy węzeł zawsze jest liściem
    if (child->key > parent->key)
        parent->right = child;
    else
        parent->left = child;
    return child;
}

void PrintInOrder(node* r)
{
    if (!r) return;
    PrintInOrder(r->left);
    std::cout << " " << r->key << " ";
    PrintInOrder(r->right);
}


void Myk(node* r, int depth = 0)
{
    if (!r) return;
    Myk(r->right, depth + 1);
    for (int i = 0; i < depth; i++) std::cout << "  ";
    std::cout << r->key << std::endl;
    Myk(r->left, depth + 1);
}

int SumTree(node* r) {
    if (!r) return 0;
    int sum = SumTree(r->left) + r->key + SumTree(r->right);
    return sum;
}

int count_nodes(node* r) {
    if (!r) return 0;
    return (count_nodes(r->left) + 1 + count_nodes(r->right));
}

double count_leaves(node* r) {
    if (!r) return 0;
    if (r->right == nullptr && r->left == nullptr)
        return 1;
    return count_leaves(r->left) + count_leaves(r->right);
}

int tree_height(node* r) {
    if (!r) return 0;

    return 1 + std::max(tree_height(r->left), tree_height(r->right));
}

node* find(node* r, int number) {
    if (!r)
        return nullptr;
    if (r->key == number)
        return r;
    if (number > r->key)
        find(r->right, number);
    else
        find(r->left, number);
}

node* tree_min(node* r, int number) {
    return nullptr;
}

int main()
{

    node* root = nullptr;
    for (int i = 0; i < 10; i++) Add_Seq(root, rand() % 100);
    PrintInOrder(root);

    std::cout << std::endl << std::endl;

    Myk(root);
    std::cout << "\n" << SumTree(root) << "\n";
    std::cout << count_nodes(root) << "\n";
    std::cout << count_leaves(root) << "\n";
    std::cout << tree_height(root) << "\n";
    node* found = find(root, -1);
    if (found)
        std::cout << "Found key: " << found->key << "\n";
    else
        std::cout << "Did not find anything\n";


    return 0;

}