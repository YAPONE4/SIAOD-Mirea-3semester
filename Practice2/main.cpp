#include <iostream>
#include "NHash.cpp"

using namespace std;

int main() {
    NHash* table = new NHash(6);
    table->createBinFile("file.txt", "BinDataFile.dat");
    table->fillHsh("BinDataFile.dat", 6);
    cout << "aaa";
    table->binFileFind(561444, "BinDataFile.dat", 6);
}