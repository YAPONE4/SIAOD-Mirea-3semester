#include <iostream>

using namespace std;



int main()
{
    unsigned int x = 7;
    x = x << 2;
    cout << hex << x << '\n';
    x = 28;
    x = x >> 2;
    cout << hex << x << '\n';
    ~x;
    cout << hex << x << '\n';
    unsigned short int x1 = 0xAEFF;
    unsigned short int mask = 0xFDFF;
    x1 = x1 & mask;
    cout << hex << x1 << endl;
    mask = 1;
    x1 = 0xAEFF;
    x1 = x1 & (~(mask << 9));
    cout << hex << x1 << endl;
    x1 = 0xAEFF;
    x1 = x1 & (~(1 << 9));
    cout << hex << x1 << endl;
    x1 = 0xACFF;
    mask = 0x0200;
    cout << hex << (x1 | mask) << endl;
    x = 147;
    mask = 0x10;
    cout << dec << (x ^ mask) << endl;
}