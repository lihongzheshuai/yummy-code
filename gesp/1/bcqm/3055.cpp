#include <iostream>
using namespace std;
int main() {
    int j;
    cin >> j;
    int a, b, c, d;
    a = j % 10;
    b = j / 10 % 10;
    c = j / 10 / 10 % 10;
    d = j / 10 / 10 / 10;
    cout << d << " " << c << " " << b << " " << a;
    return 0;
}
