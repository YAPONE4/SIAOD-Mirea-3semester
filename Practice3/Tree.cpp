#include <iostream>

using namespace std;

class Tree {
    struct Node {
        int num;
        Node* child1 = nullptr;
        Node* child2 = nullptr;
    };

    struct Q {
        Node* n;
        Q *prev;
    };

    public: 
    
    Tree() {
        root = new Node;
    }

    Node* root;

    Q* q;

    void QInit() {
        q = new Q;
        q->n = root;
        q->prev = NULL;
    }

    void addToQ(Node* n) {
        if (q->n == NULL) {
            q->prev = NULL;
            q->n = n;
        }
        else
        {
            Q* q1 = q;
            Q* newq = new Q;
            newq->n = n;
            while (q1->prev != nullptr) {
                q1 = q1->prev;
            }
            q1->prev = newq;
        }
    }

    Node* createTree(Node* t, int n) {
        int nl, nr;
        if (n != 0) {
            cin >> t->num;
            nl = n / 2;
            nr = n - nl - 1;
            t->child1 = new Node;
            createTree(t->child1, nl);
            t->child2 = new Node;
            createTree(t->child2, nr);
        }
        return t;
    }

    void printTree(Node* t, int gl = 0) {
        if (t->child1 != nullptr) {
            printTree(t->child1, gl + 1);
            cout << endl;
            for (int i = 0; i < gl; i++) {
                cout << "    " ;
            }
            cout << t->num;
            printTree(t->child2, gl + 1);
        }
    }

    int countPositiveLeafs(Node* t) {
        int n1, n2;
        if (t->child1->child1 != nullptr) {
            n1 = countPositiveLeafs(t->child1);
            n2 = countPositiveLeafs(t->child2);
        }
        else
            if (t->num > 0)
                return t->num;
            else
                return 0;
        return n1 + n2;
    }

    int countExactNumber(Node* t, int n) {
        int n1, n2;
        if (t->child1 != nullptr) {
            n1 = countExactNumber(t->child1, n);
            n2 = countExactNumber(t->child2, n);
            if (t->num == n) {
                return 1 + n1 + n2;
            }
            else
                return n1 + n2;
        }
        return 0;
    }

    Q* qPop() {
        Q* q1 = q;
        if (q->prev == NULL) {
            q = new Q;
            q->n = NULL;
        }
        else
            q = q->prev;
        return q1;
    }

    void wideQMultiply(int n) {
        Node* t;
        int c = 1;
        while (c != n) {
            c++;
            t = qPop()->n;
            if (t->child1->child1 != nullptr) {
                addToQ(t->child1);
                t->child1->num *= 2;
            }
            if (t->child2->child1 != nullptr) {
                addToQ(t->child2);
                t->child2->num *= 2;
            }
        }
    }

    void wideAll(int n) {
        QInit();
        root->num *= 2;
        wideQMultiply(n);
    }
};