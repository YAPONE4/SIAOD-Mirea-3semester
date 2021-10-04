#include <iostream>
#include <istream>
#include <fstream>
#include <string>

using namespace std;

class NHash {

    struct List {
        int key;
        int ofs;
        List *next = NULL;
    };

    List** hsh;

    public: NHash(const int n) {
        hsh = new List*[n];
    }

    struct record {
        int key;
        char data[10];
    };

    struct List* initLst(int key, int ofs) {
        struct List *lst = new List();
        lst->key = key;
        lst->ofs = ofs;
        lst->next = NULL;
        return(lst);
    }

    public: int hashF(int key, int n) {
        return(key % n);
    }

    public: List* addElem(List* lst, int key, int ofs) {
        List* lstd = lst;
        List* lstdw;
        cout << "kekich";
        /*if (lstd->next != NULL) {
            cout << "kekich";
            lstd = lstd->next;
        }*/
        cout << "kekich";
        lstdw->key = key;
        lstdw->ofs = ofs;
        lstd->next = lstdw;
        cout << lstdw->key << endl;
        return lst;
    }

    public: void fillHsh(string namebf, int n) {
        hsh = new List*[n];
        fstream obf(namebf, ios::in|ios::binary);
        if (obf.is_open()) {
            record r;
            int len = sizeof(r);
            obf.read((char*)&r, len);
            int index = hashF(r.key, n);
            cout << index << endl;
            while (!obf.eof()) {
                if (hsh[0] == NULL) {cout << "AHASDHADH" << endl;}
                cout << r.key << endl;
                if (hsh[index] == NULL) {
                    hsh[index] = initLst(r.key, obf.tellg());
                    cout << hsh[index]->key << " " << endl;
                }
                else
                {
                    cout << "kill me";
                    hsh[index] = addElem(hsh[index], r.key, obf.tellg());
                    cout << hsh[index]->key << "( " << r.key << endl;
                }
                obf.read((char*)&r, len);
                index = hashF(r.key, n);
                cout << index << endl;
            }
            cout << "hehe";
            obf.close();
            cout << "check";
        }
        else
        cout << "File not found\n";
    }

    public: int findInList(int key, List* lst) {
        do
        {
            if (lst->key == key) {
                return lst->ofs;
            }
            lst = lst->next;
        } while (lst != NULL);
        return -1;
    }

    public: void binFileFind(int key, string namebf, int n) {
        cout << "chc";
        fstream obf(namebf, ios::in|ios::binary);
        record r;
        cout << "chto";
        int len = sizeof(r);
        if (obf.is_open()) {
            //cout << "kek";
            //cout << hsh[hashF(key, n)]->key;
            obf.seekg(findInList(key, hsh[hashF(key, n)])*sizeof(record));
            obf.read((char*)&r, len);
            cout << r.key << " " << r.data;
        }
    }

    public: void createBinFile(string nametf, string namebf) {
        ifstream itf(nametf);
        fstream obf(namebf, ios::out|ios::binary);
        record r;
        int len = sizeof(r);
        while (!itf.eof()) {
            itf.getline(r.data, len, '\n');
            itf >> r.key;
            itf.get();
            obf.write((char*)&r, len);
        }
        itf.close();
        obf.close();
    }

    public: void outBinFile(string namebf) {
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
};