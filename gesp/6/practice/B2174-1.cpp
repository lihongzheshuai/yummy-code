/**
 * 题目: 【GESP】C++六级练习 luogu-B2174, 完全背包
 * 题号: B2174
 * 归属: GESP6级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-6-luogu-b2174/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// dp[j] 表示背包容量为 j 时能获得的最大总价值
int dp[1005];

int main() {
    int n, V;
    std::cin >> n >> V;

    // 外层循环：枚举每一种物品
    for (int i = 0; i < n; i++) {
        int w, val;
        std::cin >> w >> val;

        // 内层循环：正序遍历容量（完全背包的关键）
        // 从 w 开始，因为容量小于 w 时无法放入该物品
        for (int j = w; j <= V; j++) {
            // 状态转移：选或不选第 i 种物品（可以重复选）
            // dp[j - w] 可能已经包含了本轮选过的物品 i，从而实现无限选取
            if (dp[j - w] + val > dp[j]) {
                dp[j] = dp[j - w] + val;
            }
        }
    }

    // dp[V] 即为背包容量为 V 时的最大总价值
    std::cout << dp[V] << std::endl;
    return 0;
}
