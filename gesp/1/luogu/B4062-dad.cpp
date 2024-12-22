#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    double k;
    cin >> k;
    double c, f;
    c = k - 273.15;
    f = c * 1.8 + 32;
    if (f > 212) {
        cout << "Temperature is too high!";
        return 0;
    }
    printf("%.2f %.2f", c, f);
    return 0;
}