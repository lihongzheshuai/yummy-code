#include <iostream>
using namespace std;
int main() {
    double s, x;
    cin >> s >> x;
    double t = 0;
    double ans = 0;
    for (int i = 1;; i++) {
        if (ans >= s - x) {
            if (ans + t * 0.98 > s + x) {
                cout << "n";
                return 0;
            } else {
                cout << "y";
                return 0;
            }
        }
        if (i == 1) {
            t += 7;
        } else {
            t *= 0.98;
        }
        ans += t;
    }
    return 0;
}
