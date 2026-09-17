/**
 * 题目: 【GESP】C++六级练习 luogu-B2173, 多重背包
 * 题号: B2173
 * 归属: GESP6级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-6-luogu-b2173/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

// dp[j] 表示背包容量为 j 时能获得的最大总价值
int dp[1005];

int main() {
    int n, V;
    std::cin >> n >> V;

    for (int i = 0; i < n; i++) {
        int w, val, c;
        std::cin >> w >> val >> c;

        // 二进制拆分：将 c 件物品拆分为若干"捆"
        // 每捆的件数依次为 1, 2, 4, 8, ...，最后一捆为余数
        int rest = c; // 剩余待拆分的件数
        for (int bundle = 1; rest > 0; bundle *= 2) {
            // 当前这捆的件数：取 bundle 和剩余件数的较小值
            int cnt = std::min(bundle, rest);
            rest -= cnt;

            // 当前这捆的总体积和总价值
            int bw = cnt * w;
            int bv = cnt * val;

            // 对这一捆做 01 背包（逆序遍历容量）
            for (int j = V; j >= bw; j--) {
                dp[j] = std::max(dp[j], dp[j - bw] + bv);
            }
        }
    }

    std::cout << dp[V] << std::endl;
    return 0;
}
