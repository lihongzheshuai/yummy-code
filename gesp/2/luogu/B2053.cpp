#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double ee = b * b - 4 * a * c;
    if (ee >= 0) {
        double d = sqrt(ee);
        double e = d - b;
        double x1 = e / (2 * a);
        double e_x2 = -1 * b - d;
        double x2 = e_x2 / (2 * a);
        if (x1 == x2) {
            printf("x1=x2=%.5f", x1);
        } else {
            if (x1 > x2) {
                printf("x1=%.5f;x2=%.5f", x2, x1);
            } else {
                printf("x1=%.5f;x2=%.5f", x1, x2);
            }
        }
    } else {
        cout << "No answer!";
    }

    return 0;
}
