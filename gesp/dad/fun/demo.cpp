#include <cmath>
#include <iostream>
using namespace std;

const double PI = acos(-1.0);

int main() {
    long double a[8], s;
    int i, j;
    for (i = 0; i < 7; i++) {
        a[i] = cos(2 * i * PI / 7);
    }
    while (1) {
        s = 0;
        a[7] = a[0];
        for (i = 0; i < 7; i++) {
            a[i] -= a[i + 1];
            s += a[i] * a[i];
        }
        if (log10(s) < -10) {
            cout << "shrunk" << endl;
            break;
        }
        if (log10(s) > 20) {
            cout << "overflowed" << endl;
            break;
        }
    }
}