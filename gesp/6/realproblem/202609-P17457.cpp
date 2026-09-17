/**
 * 题目: 【GESP真题】GESP六级 / CSP-J 题解：luogu-P17457 [GESP202609 六级] 数组划分
 * 题号: P17457
 * 归属: GESP6级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-6-luogu-p17457-array-partition/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-P17457
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    vector<long long> a(n + 1);
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    const long long INF = 1e18;
    vector<long long> dp(n + 1, INF);
    dp[0] = 0; // 基础状态

    // O(n^2) 动态规划
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            long long seg_sum = prefix[i] - prefix[j];
            long long cost = dp[j] + seg_sum * seg_sum;
            if (cost < dp[i]) {
                dp[i] = cost;
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}
