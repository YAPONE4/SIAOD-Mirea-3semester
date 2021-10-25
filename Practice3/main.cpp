#include <iostream>
#include "Tree.cpp"

using namespace std;

int main() {
    int n;
    cin >> n;
    Tree tr(n);
    tr.root = tr.createTree(tr.root, 6);
    tr.printTree(tr.root);
}