#include <iostream>
using namespace std;

// P17830 [CSP-J 2026] 纸牌游戏 (card)
// 核心算法：桌面最左端纸牌不变量洞察 + 跳向最后出现位置的 O(n) 线性状态递推 (DP)
// 关键性质：
// 1. 第 i 局打出的第一张牌 a[i] 位于桌面最左端（左边没有任何牌），因此永远不会被左侧的牌连带消除；
// 2. 每当后续再次打出点数 a[i] 时，都会把 a[i] 右侧的所有牌清空；
// 3. 当 a[i] 在全序列中最后一次出现的位置 p = last_pos[a[i]] 被打出时，桌面被重置为仅剩一张 [a[i]]；
// 4. 在位置 p 之后，点数 a[i] 绝不再出现，因此右侧后续留下的牌完全等价于第 (p + 1) 局游戏的最终桌面！

// 牌的总数 n 最大为 5 * 10^5
const int MAXN = 500005;

// a[i] 存储从上到下第 i 张牌的点数
int a[MAXN];

// last_pos[v] 记录点数 v 在整个纸牌序列 a[1..n] 中最后一次出现的下标位置
int last_pos[MAXN];

// cnt[i] 表示在全部 n 局游戏中，有多少局游戏的桌面状态递推链会经过起点状态 i
long long cnt[MAXN];

// ans[v] 统计最终有多少局游戏结束时，桌面上留有点数为 v 的纸牌
long long ans[MAXN];

int main() {
    // 读取纸牌总数 n 和点数种类数 m
    int n, m;
    cin >> n >> m;

    // 读取每张牌的点数，同时预处理每个点数最后一次出现的位置 last_pos
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // 不断覆盖更新，循环结束时 last_pos[v] 即为点数 v 最后一次出现的下标
        last_pos[a[i]] = i;
        // 初始时，第 i 局游戏本身从位置 i 开局，因此每个位置 i 初始拥有 1 个游戏局起点
        cnt[i] = 1;
    }

    // 按照位置从左到右（1 -> n）正向线性递推，传递每局游戏的状态链：i -> (last_pos[a[i]] + 1)
    for (int i = 1; i <= n; i++) {
        // 当前状态 i 打出的首张牌点数为 val = a[i]
        int val = a[i];

        // 1. 统计贡献：
        //    所有经过状态 i 的 cnt[i] 局游戏，其最终桌面上一定永久保留这张最左端的牌 val
        //    且由于后续跳转到 last_pos[val] + 1 之后再无点数 val，不会发生重复计数
        ans[val] += cnt[i];

        // 2. 状态转移：
        //    当位置 last_pos[val] 的最后一张 val 打出后，桌面仅剩 [val]，
        //    随后的出牌过程完全等价于转入第 nxt = last_pos[val] + 1 局游戏的状态
        int nxt = last_pos[val] + 1;
        if (nxt <= n) {
            cnt[nxt] += cnt[i];
        }
    }

    // 依次输出点数 1 到 m 各自在多少局游戏结束时留在桌面上
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << (i == m ? "" : " ");
    }
    cout << endl;

    return 0;
}
