/**
 * 题目: 【GESP】C++六级练习 luogu-B2174, 完全背包
 * 题号: B2174
 * 归属: GESP6级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-6-luogu-b2174/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// dp[i][j] 表示：前 i 种物品、背包容量为 j 时的最大总价值
int dp[1005][1005];
int w[1005], val[1005];

int main() {
    int n, V;
    std::cin >> n >> V;

    for (int i = 1; i <= n; i++) {
        std::cin >> w[i] >> val[i];
    }

    // 外层循环：枚举前 i 种物品
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            // 不选第 i 种物品：继承前 i-1 种物品的结果
            dp[i][j] = dp[i - 1][j];
            // 选（至少）一件第 i 种物品
            // 注意这里是 dp[i][j - w[i]]，而不是 dp[i-1][j - w[i]]
            // 用的是"本行"已更新的值，所以同一物品可以被反复选取
            if (j >= w[i] && dp[i][j - w[i]] + val[i] > dp[i][j]) {
                dp[i][j] = dp[i][j - w[i]] + val[i];
            }
        }
    }

    std::cout << dp[n][V] << std::endl;
    return 0;
}
