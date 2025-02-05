#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 4; i <= n; i += 2) {
        int other = 0;
        for (int j = 2; j <= i / 2; j++) {
            bool flag = true;
            other = i - j;
            for (int k = 2; k <= sqrt(j); k++) {
                if (j % k == 0) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                continue;
            } else {
                for (int k = 2; k <= sqrt(other); k++) {
                    if (other % k == 0) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                cout << i << "=" << j << "+" << other << endl;
                break;
            }
        }
    }
    return 0;
}