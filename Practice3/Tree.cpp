#include <iostream>

using namespace std;

class Tree {
    struct Node {
        int n;
        Node* child = nullptr;
        Node* child2 = nullptr;
        Node* parent = nullptr;
    };

    int *m;
    int num;
    Node *root;

    Tree(int n, int *m, int num) {
        this->m = m;
        this->root->n = n;
        this->num = num;
    }

    int createTree(Node *node, int sch = 1) {
        
    }
};