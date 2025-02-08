#include <iostream>
using namespace std;
int main() {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; i++) {
        int j, re = i;
        while (re != 0) {
            j = re % 10;
            if (j == 2) {
                ans++;
            }
            re /= 10;
        }
    }
    cout << ans;
    return 0;
}
