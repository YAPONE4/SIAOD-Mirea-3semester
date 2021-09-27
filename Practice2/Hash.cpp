#include <iostream>
#include <list>
#include <ctype.h>
#include <fstream>
#include <string>

using namespace std;

class Hash
{
    int n;

    list<int> *table;

    int hashFunction(int key) {
        return(key % n);
    }

    int odigits(string s) {
        string news;
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i])) 
            {
                news += s[i];
            }
        }
        return stoi(news);
    }

    Hash(int n)
    {
        this->n = n;
        table = new list<int>[n];
    }

    void insertItems() {
        string line;
        ifstream f;
        f.open("file.dat");
        while (getline(f, line)) {
            int key = odigits(line);
            int index = hashFunction(key);
            table[index].push_back(key);
        }
    }

    void delItem(int key) {
        int index = hashFunction(key);
        
    }

    void rehash(int *m[], int size, int newn) {
        for(int i = 0; i < size; i++) {
            table[*m[i] % newn] = table[*m[i] % size];
        }
    }
};