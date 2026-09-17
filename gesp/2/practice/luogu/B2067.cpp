#include <iostream>
using namespace std;
int main() {
    int m, n, ans = 0;
    cin >> m >> n;
    int n1;
    for (int i = 1; i <= n; i++) {
        cin >> n1;
        if (m - n1 >= 0) {
            m -= n1;

        } else {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
