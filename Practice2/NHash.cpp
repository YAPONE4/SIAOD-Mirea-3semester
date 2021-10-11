#include <iostream>
#include <istream>
#include <fstream>
#include <string>

using namespace std;

class NHash {

    struct List {
        int key = 0;
        int ofs = 0;
        List *next = NULL;
    };

    List** hsh = NULL;

    public: NHash(const int n) {
        hsh = new List*[n];
        for (int i = 0; i < n; i++) {
            hsh[i] = nullptr;
        }
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
        List* lstdw = new List;
        lstdw->key = key;
        lstdw->ofs = ofs;
        lstdw->next = lstd;
        return lstdw;
    }

    public: void fillHsh(string namebf, int n) {
        fstream obf(namebf, ios::in|ios::binary);
        if (obf.is_open()) {
            record r;
            int len = sizeof(r);
            obf.read((char*)&r, len);
            int index = hashF(r.key, n);
            while (!obf.eof()) {
                if (hsh[index] == NULL) {
                    hsh[index] = initLst(r.key, obf.tellg());
                }
                else
                {
                    hsh[index] = addElem(hsh[index], r.key, obf.tellg());
                }
                obf.read((char*)&r, len);
                index = hashF(r.key, n);
            }
            obf.close();
        }
        else
        cout << "File not found\n";
    }

    public: void reHsh(string namebf, int n) {
        *hsh = new List[n * 2];
        for (int i = 0; i < n * 2; i++) {
            hsh[i] = nullptr;
        }
        fillHsh(namebf, n * 2);
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

    public: void delFromHsh(int key, int n) {
        List* lst, *lstd;
        int index = hashF(key, n);
        lst = hsh[index];
        lstd = lst;
        if (lst->key == key) {
            hsh[index] = lst->next;
        }
        else {
            while (lstd->next != NULL) {
                if (lstd->next->key == key) {
                    lstd->next = lstd->next->next;
                }
            }
            hsh[index] = lst;
        }
    }

    public: void binFileFind(int key, string namebf, int n) {
        fstream obf(namebf, ios::in|ios::binary);
        record r;
        int len = sizeof(r);
        int chck = findInList(key, hsh[hashF(key, n)]);
        if (obf.is_open()) {
            if (chck != -1) {
            obf.seekg(chck - len);
            obf.read((char*)&r, len);
            cout << r.key << " " << r.data;
            }
            else
            {
                cout << "Key not found...";
            }
        }
        obf.close();
    }

    public: void binFileDel(int key, string namebf, int n) {
        ofstream obf(namebf, ios::out|ios::binary|ios::in);
        delFromHsh(key, n);
        record r;
        r.key = 0;
        int len = sizeof(r);
        obf.seekp(findInList(key, hsh[hashF(key, n)]) - len);
        obf.write((char*)&r, len);
        obf.close();
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

    public: void outpHsh(int n) {
        for (int i = 0; i < n; i++) {
            List* lst = hsh[i];
            while (lst != NULL) {
                cout << lst->key << " " << lst->ofs << endl;
                lst = lst->next;
            }
        }
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