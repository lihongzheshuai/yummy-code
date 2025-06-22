#include <iostream>
using namespace std;
int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        unsigned long long result = 1;
        if (n & 1) {
            for (int i = 2; i <= n; i += 2) {
                result *= i;
            }
        } else {
              for (int i = 1; i <= n; i += 2) {
                result *= i;
            }
        }
        cout << result * 2 << endl;
    }
    return 0;
}