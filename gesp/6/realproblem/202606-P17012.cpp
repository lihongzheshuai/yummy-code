/**
 * 题目: 【GESP】C++六级真题 luogu-P17012, [GESP202606 六级] 条形蛋糕
 * 题号: P17012
 * 归属: GESP6级 (202606认证真题)
 * 博客: https://www.coderli.com/gesp-6-luogu-p17012/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    int p[1005];    // 价格表：p[i] 表示长度为 i 的蛋糕块的价格
    int dp[1005];   // dp[i] 表示长度为 i 的蛋糕的最大总售价

    // 读入各长度蛋糕块的价格
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i];
    }

    dp[0] = 0; // 边界条件：长度为 0 的蛋糕，售价为 0

    // 自底向上计算 dp[1], dp[2], ..., dp[n]
    for (int i = 1; i <= n; i++) {
        dp[i] = 0; // 初始化为 0，准备取最大值
        // 枚举第一段切下来的长度 j（从 1 到 i）
        for (int j = 1; j <= i; j++) {
            // p[j] 是长度为 j 的蛋糕块的价格
            // dp[i - j] 是剩余长度 i - j 的最大售价（已在前面计算好）
            dp[i] = std::max(dp[i], p[j] + dp[i - j]);
        }
    }

    // dp[n] 即为长度为 n 的蛋糕的最大总销售价格
    std::cout << dp[n] << std::endl;
    return 0;
}
