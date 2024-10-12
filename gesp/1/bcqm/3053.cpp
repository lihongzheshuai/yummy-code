#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    int b, c, d;
    b = a % 10;
    c = a / 10 % 10;
    d = a / 10 / 10;
    int e;
    e = b * 100 + c * 10 + d;
    cout << e;
    return 0;
}
