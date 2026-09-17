/**
 * 题目: 【GESP】C++五级练习（前缀和练习） luogu-P1387 最大正方形
 * 题号: P1387
 * 归属: GESP5级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-p1387/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main() {

    int n, m;
    std::cin >> n >> m;

    // dp[i][j] 表示以 (i, j) 为右下角的最大正方形边长
    // 使用 vector 动态申请，初始化为 0
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    int max_side = 0;
    int val;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> val;
            if (val == 1) {
                // 状态转移方程：当前位置由左、上、左上的最小值决定
                // std::min({a, b, c}) 需要 C++11 支持
                dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                // 更新全局最大值
                max_side = std::max(max_side, dp[i][j]);
            }
        }
    }

    std::cout << max_side << std::endl;

    return 0;
}
