#include <iostream>

using namespace std;

void coutp(unsigned int x)
{
    int count = 0;
    int newx = x;
    while (newx != 0)
    {
        newx /= 2;
        count += 1;
    }
    newx = 0;
    if (count % 4 != 0)
    {
        newx = 1;
    }
    newx += count / 4;
    int n = sizeof(int) * newx;
    unsigned mask = (1 << (n - 1));
    for(int i = 1; i <= n; i++)
    {
        cout << ((x & mask) >> (n - i));
        mask = mask >> 1;
    }
}

int main()
{
    // Ex.1
    cout << "Ex.1: ";
    unsigned int n = 0x1CB5; // 0001 1100 1011 0101
    unsigned mask = 0x5555; // 0101 0101 0101 0101
    n = n | mask;
    coutp(n);
    cout << endl << endl;
    // Ex.2
    cout << "Ex.2: ";
    unsigned int n1;
    cin >> n1;
    unsigned mask2 = 0x7FFFFE1F; // 1....1 1110 0001 1111
    n1 = n1 & mask2;
    coutp(n1);
    cout << endl << endl;
    // Ex.3
    cout << "Ex.3: ";
    unsigned int n2;
    cin >> n2;
    n2 = n2 << 5;
    coutp(n2);
    // Ex.4
    cout << endl << endl << "Ex.4: ";
    unsigned int n3;
    cin >> n3;
    n3 = n3 >> 5;
    cout << n3 << endl;
    coutp(n3);
}