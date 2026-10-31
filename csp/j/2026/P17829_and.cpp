#include <iostream>
using namespace std;

// P17829 [CSP-J 2026] 按位与 (and)
// 按二进制位从高到低贪心构造最优掩码
const int MAXN = 200005;
int a[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    // a_i < 2^30，最高二进制位为第 29 位，从高位到低位依次试填 1
    for (int bit = 29; bit >= 0; bit--) {
        int target = ans | (1 << bit);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if ((a[i] & target) == target) {
                cnt++;
            }
        }
        // 若至少有 m 个数同时具备 target 的所有二进制 1 位，则该位可以置 1
        if (cnt >= m) {
            ans = target;
        }
    }

    cout << ans << endl;
    return 0;
}
