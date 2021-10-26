#include <iostream>
#include "Tree.cpp"

using namespace std;

int main() {
    cout << "Type your numbers: " << endl;
    Tree tr;
    tr.root = tr.createTree(tr.root, 7);
    tr.printTree(tr.root);
    cout << endl << "Sum of positive leafs:" << endl;
    cout << tr.countPositiveLeafs(tr.root);
    cout << endl << "Sum of number 6: ";
    cout << tr.countExactNumber(tr.root, 6);
    cout << endl << "Multiplying tree by 2, going through widely..." << endl;
    tr.wideAll(7);
    tr.printTree(tr.root);
}