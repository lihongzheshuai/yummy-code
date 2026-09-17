#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int a, b, n;
    cin >> a >> b >> n;
    if (a == b) {
        cout << 0;
        return 0;
    }
    int c;
    for (int i = 1; i <= n; i++) {
        a = a * 10;
        c = a / b;
        a = a % b;
    }
    cout << c;
    return 0;
}
