#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

struct node
{
    int key;

    node* left;
    node* right;
    node* parent;
};

node* dummy;

node* Add2(node*& r, int number, node* par)
{
    if (r == nullptr)
    {
        r = new node;
        r->key = number;
        r->left = r->right = nullptr;  // nowy węzeł zawsze jest liściem
        r->parent = par;
        return r;
    }

    if (number == r->key) return r;
    if (number > r->key) return Add2(r->right, number, r);
    return Add2(r->left, number, r);
}

bool IsRoot(node* r)
{
    if (!r) { cout << "E2"; return false; }
    return (r->parent == dummy);
}

char WhichChildIAm(node* r)
{
    if (r == r->parent->left) return 'l';
    return 'r';
}
void Rotate(node* B)
{
    if (!B) { cout << "E1"; return; }
    if (IsRoot(B)) return;

    node* A = B->parent;     //A

    if (A->left == B)
    {//rotate right
        node* Beta = B->right;  //BETA

        B->parent = A->parent;  //P
        if (A->parent->left == A) A->parent->left = B; else A->parent->right = B;

        B->right = A;
        A->parent = B;

        A->left = Beta;
        if (Beta) Beta->parent = A;
    }
    else
    {//rotate left
        node* Beta = B->left;  //BETA

        B->parent = A->parent;  //P
        if (A->parent->left == A) A->parent->left = B; else A->parent->right = B;

        B->left = A;
        A->parent = B;

        A->right = Beta;
        if (Beta) Beta->parent = A;
    }
}


void Myk(node* r, int depth = 0)
{
    if (!r) return;
    Myk(r->right, depth + 1);
    for (int i = 0; i < depth; i++) cout << "  ";
    cout << r->key << endl;
    Myk(r->left, depth + 1);
}

void Splay(node* r)
{
    if (!r) return;
    // cout<<"o";
    while (!IsRoot(r))
    {
        if (IsRoot(r->parent)) { Rotate(r); continue; } //zig
        if (WhichChildIAm(r) != WhichChildIAm(r->parent)) { Rotate(r);  Rotate(r);  continue; } //zig zag
        Rotate(r->parent); Rotate(r); //zig zig
    }
}

node* Nastepnik(node* n) {
    if (n->right != nullptr)
        return Min;

}

int main()
{
    dummy = new node;
    for (int i = 0; i < 12; i++) Add2(dummy->right, (rand() + 7) % 15, dummy);

    Myk(dummy->right);
    cout << endl << endl << endl << endl;

    node* dziewiatka = dummy->right->right;
    node* jedenastka = dummy->right->right->right;

    // Rotate(jedenastka);
    // Rotate(jedenastka);
    // Rotate(dummy->right->left);

    Splay(jedenastka);
    cout << endl << endl << endl << endl;
    Myk(dummy->right);
    cout << endl << endl << endl << endl;

    return 0;

}



