#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = n - 1; i >= 2; i--) {
        if (n % i == 0) {
            int j = n / i;
            bool flag = true;
            for (int k = 2; k <= sqrt(i); k++) {
                if ((i % k == 0 && i != k) || (j % k == 0 && j != k)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << i;
                break;
            }
        }
    }
    return 0;
}