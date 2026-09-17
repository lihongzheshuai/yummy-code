/**
 * 题目: 【GESP真题】GESP七级 / CSP-S 题解：luogu-P17460 [GESP202609 七级] 括号序列
 * 题号: P17460
 * 归属: GESP7级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-7-luogu-p17460-bracket-sequence/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-P17460
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    string s;
    cin >> s;

    // dp[j] 表示净左括号数为 j 的子序列总数
    vector<int> dp(n + 2, 0);
    dp[0] = 1;

    for (char c : s) {
        if (c == '(') {
            // 逆序更新避免后效性
            for (int j = n; j >= 1; --j) {
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        } else if (c == ')') {
            // 顺序更新净差值减少
            for (int j = 0; j <= n; ++j) {
                dp[j] = (dp[j] + dp[j + 1]) % MOD;
            }
        }
    }

    cout << dp[0] << "\n";

    return 0;
}
