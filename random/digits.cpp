#include <iostream>

using namespace std;

int digitsF(int a, int b, int num = 0) {
    if (a < b) {
        return num;
    }
    else
    {
        num++;
        digitsF(a - b, b, num);
    }
}

int main() {
    cout << digitsF(328, 5);
}