#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    // b十位 ,c个位。
    int b, c;
    b = a / 10;
    c = a % 10;
    int d;
    d = c * 10 + b;
    cout << d;
    return 0;
}
