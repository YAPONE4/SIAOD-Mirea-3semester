#include <iostream>

using namespace std;

void recurInput(char n)
{
    char newn;
    cin >> newn;
    if (newn == '.') {
        cout << n;
    }
    else
    {
        recurInput(newn);
        cout << n;
    }
}

int main() {
    char n;
    cin >> n;
    recurInput(n);
}