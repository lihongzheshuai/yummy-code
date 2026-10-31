#include <iostream>
using namespace std;

// P17830 [CSP-J 2026] 纸牌游戏 (card)
// 状态递推 / 动态规划：第 i 局首张牌 a[i] 永远在最左端不被左侧牌消除，
// 且当 a[i] 在其最后一次出现位置 last_pos[a[i]] 打出时，桌面重置为仅剩 [a[i]]，
// 后续桌面状态完全等价于第 (last_pos[a[i]] + 1) 局的最终桌面。
const int MAXN = 500005;
int a[MAXN];
int last_pos[MAXN];
long long cnt[MAXN];
long long ans[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last_pos[a[i]] = i;
        cnt[i] = 1; // 初始时第 i 局游戏从位置 i 出发
    }

    for (int i = 1; i <= n; i++) {
        int val = a[i];
        // 所有到达状态 i 的游戏局，其最终桌面上一定包含点数 val
        ans[val] += cnt[i];
        // 在 val 最后一次出现的位置 last_pos[val] 之后，接续状态 (last_pos[val] + 1)
        int nxt = last_pos[val] + 1;
        if (nxt <= n) {
            cnt[nxt] += cnt[i];
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << (i == m ? "" : " ");
    }
    cout << endl;

    return 0;
}
