#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int d = i, num;
        bool flag = false;
        if (i % 7 == 0) {
            flag = true;
            continue;
        }
        while (d != 0) {
            num = d % 10;
            if (num == 7) {
                flag = true;
                break;
            }
            d /= 10;
        }
        if (!flag) {
            ans += i * i;
        }
    }
    cout << ans;
    return 0;
}
