#include <iostream>
#include "NHash.cpp"

using namespace std;

int main() {
    int key;
    cout << "Type your key: ";
    cin >> key;
    NHash* table = new NHash(6);
    table->createBinFile("file.txt", "BinDataFile.dat");
    table->fillHsh("BinDataFile.dat", 6);
    table->reHsh("BinDataFile.dat", 6);
    table->binFileDel(123244, "BinDataFile.dat", 12);
    table->binFileFind(key, "BinDataFile.dat", 12);
}