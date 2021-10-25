#include <iostream>

using namespace std;

class Tree {
    struct Node {
        int num;
        Node* child1 = nullptr;
        Node* child2 = nullptr;
    };

    public: 
    
    Tree(int n) {
        root->num = n;
    }

    Node* root;

    Node* createNode(int d) {
        Node* node = new Node;
        node->num = d;
        return node;
    }

    Node* createThree (int droot, int dleft, int dright) {
        Node* root;
        root = createNode(droot);
        root->num = droot;
        root->child1 = createNode(dleft);
        root->child2 = createNode(dright);
        return root;
    }

    void printThreeTree(Node* root) {
        cout << root->num << endl << "    " << root->child1->num << endl << "    " << root->child2->num;
    }

    Node* createTree(Node* t, int n) {
        int nl, nr;
        if (n != 0) {
            t = new Node;
            cin >> t->num;
            nl = n / 2;
            nr = n - nl - 1;
            createTree(t->child1, nl);
            createTree(t->child2, nr);
        }
        return t;
    }

    void printTree(Node* t, int gl = 1) {
        if (t != nullptr) {
            cout << t->num;
            for (int i = 0; i < gl; i++) {
                cout << "    ";
            }
            printTree(t->child1, gl + 1);
            printTree(t->child2, gl + 1);
        }
    }
};