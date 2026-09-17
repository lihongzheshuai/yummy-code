/**
 * 题目: 【CSP】CSP-J 2019真题 | 纪念品 luogu-P5662 （适合GESP六级及以上考生练习）
 * 题号: P5662
 * 归属: GESP6级
 * 博客: https://www.coderli.com/csp-j-2019-p5662/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

// 根据题目数据范围，任意时刻金币数不超过 10000，加上预留空间设定为 10005
const int MAXN = 105;
const int MAXT = 105;
const int MAXM = 10005;

int P[MAXT][MAXN]; // 记录第 i 天第 j 种纪念品的价格
int dp[MAXM];      // dp[w] 表示使用 w 金币能获得的最大利润

int main() {
    // 优化输入输出流性能
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T, N, M;
    std::cin >> T >> N >> M;

    // 读入 T 天 N 种纪念品的价格
    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> P[i][j];
        }
    }

    // T 天之间，共需进行 T-1 轮跨天的买卖决策
    for (int i = 1; i < T; i++) {
        // 每轮决策前将 dp 数组清零
        std::memset(dp, 0, sizeof(dp));

        for (int j = 1; j <= N; j++) {
            int cost = P[i][j];                // 今日买入价格（完全背包中的重量）
            int profit = P[i + 1][j] - P[i][j]; // 明日卖出所获得的纯利润（完全背包中的价值）

            // 只有明日价格高于今日价格（即能赚到钱）时，才考虑交易
            if (profit <= 0) continue;

            // 完全背包：正向遍历资金容量
            for (int w = cost; w <= M; w++) {
                dp[w] = std::max(dp[w], dp[w - cost] + profit);
            }
        }
        // 这一天的买卖完成后，获得的最大利润 dp[M] 累加进手头的金币 M 中，作为下一天的本金
        M += dp[M];
    }

    // 输出最终第 T 天结束卖出所有纪念品后，能拥有的最大金币数量
    std::cout << M << "\n";

    return 0;
}
