#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long factorial = 1;
    if (n != 0) {
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }
    }
    for (long long z = 1; ; z++) {
        if (z == 1) {
            if (n == 1) {
                cout << 1 << " " << 0 << " " << 1 << endl;
                break;
            } else {
                continue;
            }
        } else {
            long long numerator = z * (factorial - n);
            if (numerator % (z - 1) == 0) {
                long long x = numerator / (z - 1);
                long long y = x - z * n;
                cout << x << " " << y << " " << z << endl;
                break;
            }
        }
    }
    return 0;
}