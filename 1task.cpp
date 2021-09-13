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
    cout << "Prakticheskaya rabota no1. Prin Alexey IKBO-11-20. Var 4" << endl << endl;
    // Ex.1
    cout << "Ex.1: " << endl << " n = 0x1CBD = 0001 1100 1011 0101" << endl << "Result: ";
    unsigned short n = 0x1CB5; // 0001 1100 1011 0101
    unsigned short mask = 0x5555; // 101 0101 0101 0101
    /*unsigned mask = 1;
    for (int i = 0; i < 7; i++)
    {
        mask = (mask << 2) + 1;
    }*/
    n = n | mask;
    coutp(n);
    cout << endl << endl;
    // Ex.2
    cout << "Ex.2: " << endl << "Type your n1: ";
    unsigned short n1;
    cin >> n1;
    // unsigned short mask2 = 0x7E1F; // 111 1110 0001 1111
    unsigned short mask2 = ~((~(~0 << 4)) << (5));
    n1 = n1 & mask2;
    cout << "Result: ";
    coutp(n1);
    cout << endl << endl;
    // Ex.3
    cout << "Ex.3: " << endl << "Type your n2: ";
    unsigned short n2;
    cin >> n2;
    n2 = n2 << 5;
    cout << "Result: ";
    coutp(n2);
    // Ex.4
    cout << endl << endl << "Ex.4: " << endl << "Type your n3: ";
    unsigned short n3;
    cin >> n3;
    n3 = n3 >> 5;
    cout << "Result: ";
    coutp(n3);
    // Ex.5s
    cout << endl << endl << "Ex.5:" << endl << "n4 = ";
    unsigned int n4, nc, x, mask4, count;
    count = 0;
    cin >> n4;
    cout << "nc = ";
    cin >> nc;
    x = n4;
    while (x != 0)
    {
        x /= 2;
        count++;
    }
    mask4 = (1 << count) >> (count - nc + 1);
    n4 = n4 | mask4;
    cout << "Result: ";
    coutp(n4);
}