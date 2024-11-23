#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int c;
    cin >> c;
    int mod = n % 7;
    int ans = mod;
    for (int i = 1; i < c; i++) {
        ans %= 7;
        ans *= mod;
    }
    if (ans % 7 == 0) {
        cout << "Sunday";
    }
    if (ans % 7 == 1) {
        cout << "Monday";
    }
    if (ans % 7 == 2) {
        cout << "Tuesday";
    }
    if (ans % 7 == 3) {
        cout << "Wednesday";
    }
    if (ans % 7 == 4) {
        cout << "Thursday";
    }
    if (ans % 7 == 5) {
        cout << "Friday";
    }
    if (ans % 7 == 6) {
        cout << "Saturday";
    }
    return 0;
}
