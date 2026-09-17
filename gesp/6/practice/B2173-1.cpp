/**
 * 题目: 【GESP】C++六级练习 luogu-B2173, 多重背包
 * 题号: B2173
 * 归属: GESP6级
 * 解法: 解法 1 / 共 2 种解法
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

    // 外层循环：枚举每一种物品
    for (int i = 0; i < n; i++) {
        int w, val, c;
        std::cin >> w >> val >> c;

        // 中层循环：逆序遍历容量（与 01 背包相同）
        // 逆序保证 dp[j - k*w] 读到的是上一轮的旧值
        for (int j = V; j >= w; j--) {
            // 内层循环：枚举第 i 种物品选取的件数 k（从 1 到 c）
            // k=0 对应"不选"，dp[j] 保持不变，无需显式处理
            for (int k = 1; k <= c && k * w <= j; k++) {
                dp[j] = std::max(dp[j], dp[j - k * w] + k * val);
            }
        }
    }

    // dp[V] 即为背包容量为 V 时的最大总价值
    std::cout << dp[V] << std::endl;
    return 0;
}
