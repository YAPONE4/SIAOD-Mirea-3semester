#include <iostream>
#include <istream>
#include <fstream>
#include <string>


using namespace std;

struct record {
    int key;
    char data[10];
};

void CreateBinFile(string nametf, string namebf) {
    ifstream itf(nametf);
    fstream obf(namebf, ios::out|ios::binary);
    record r;
    int len = sizeof(r);
    while (!itf.eof()) {
        itf >> r.key;
        itf.get();
        itf.getline(r.data, len, '\n');
        obf.write((char*)&r, len);
    }
    itf.close();
    obf.close();
}

void outBinFile(string namebf) {
    fstream obf(namebf, ios::in|ios::binary);
    if (obf.is_open()) {
        record r;
        int len = sizeof(r);
        obf.read((char*)&r, len);
        while (!obf.eof()) {
            cout << r.key << " " << r.data << "\n";
            obf.read((char*)&r, len);
        }
        obf.close();
    }
    else
    cout << "File not found\n";
}

int main()
{
    CreateBinFile("file.txt", "BinDataFile.dat");
    outBinFile("BinDataFile.dat");
}