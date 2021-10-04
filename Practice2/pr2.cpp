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
        itf.getline(r.data, len, '\n');
        itf >> r.key;
        itf.get();
        obf.write((char*)&r, len);
        cout << "check 3";
    }
    cout << "check1";
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
            cout << "check2";
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