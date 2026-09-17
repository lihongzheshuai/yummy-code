/**
 * 题目: 【NOIP】2005真题解析 luogu-P1048 采药（适合GESP六级以上练习）
 * 题号: P1048
 * 归属: GESP6级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/noip-2005-luogu-p1048/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

// dp[i][j] 表示：只考虑前 i 株草药，在假设背包容量（总时间）为 j 时的最大价值
int dp[105][1005];

// 存储每株草药的采摘时间（重量）和价值
int w[105], v[105];

int main() {
    int T, M;
    std::cin >> T >> M;

    // 读入所有草药的重量（时间）和价值
    for (int i = 1; i <= M; i++) {
        std::cin >> w[i] >> v[i];
    }

    // 初始化：由于全局变量默认初始值为 0，dp[0][j] 全为 0，代表没有任何草药可选时价值为 0

    // 外层循环：依次考虑前 1 ~ M 株草药
    for (int i = 1; i <= M; i++) {
        // 内层循环：枚举假设的背包总容量 j（从最小容量 0 到最大可用时间 T）
        for (int j = 0; j <= T; j++) {
            // 默认不选第 i 株草药：继承只考虑前 i-1 株草药、容量为 j 时的最大价值
            dp[i][j] = dp[i - 1][j];

            // 如果假设的容量 j 足够装下第 i 株草药，尝试进行采摘决策
            if (j >= w[i]) {
                // 在“不采摘”（dp[i-1][j]）和“采摘”（前 i-1 株在剩余容量 j-w[i] 下的最优价值 + 当前草药价值 v[i]）中取最大值
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    // dp[M][T] 即为在总时间 T 内，考虑全部 M 株草药能采摘到的最大价值
    std::cout << dp[M][T] << std::endl;
    return 0;
}
