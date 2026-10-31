#include <iostream>
#include <algorithm>
using namespace std;

// P17828 [CSP-J 2026] 回文串 (string)
// 游程编码 (Run-Length Encoding) 上的双指针模拟
const int MAXN = 200005;
long long a[MAXN];
char c[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }

    int l = 1, r = n;
    long long ans = 0;

    // 从字符串首尾两端同时向中间对齐消去
    while (l < r) {
        long long take = min(a[l], a[r]);
        if (c[l] != c[r]) {
            ans += take;
        }
        a[l] -= take;
        a[r] -= take;
        if (a[l] == 0) {
            l++;
        }
        if (a[r] == 0) {
            r--;
        }
    }

    cout << ans << endl;
    return 0;
}
