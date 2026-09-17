/**
 * 题目: 【GESP真题】GESP四级 / CSP-J 题解：luogu-B4579 [GESP202609 四级] 新汉诺塔
 * 题号: B4579
 * 归属: GESP4级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b4579-new-hanoi/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-B4579
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    // f[i]: 顺时针跨 1 根柱子（A->B）
    // g[i]: 顺时针跨 2 根柱子（A->C）
    vector<long long> f(n + 1, 0);
    vector<long long> g(n + 1, 0);

    f[1] = 1;
    g[1] = 2;

    for (int i = 2; i <= n; ++i) {
        f[i] = 2 * g[i - 1] + 1;
        g[i] = 2 * g[i - 1] + f[i - 1] + 2;
    }

    cout << g[n] << "\n";

    return 0;
}
