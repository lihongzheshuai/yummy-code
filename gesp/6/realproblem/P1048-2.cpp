/**
 * 题目: 【NOIP】2005真题解析 luogu-P1048 采药（适合GESP六级以上练习）
 * 题号: P1048
 * 归属: GESP6级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/noip-2005-luogu-p1048/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

// dp[j] 表示：在总时间（总容量）限制为 j 的情况下的最大最优价值
int dp[1005];

int main() {
    int T, M;
    std::cin >> T >> M;

    // 依次读入并处理每一株草药
    for (int i = 0; i < M; i++) {
        int w, v;
        std::cin >> w >> v;

        // 逆序（从大到小）遍历假设的总容量 j
        // 注意：只需递减到 w 即可（当容量比当前草药重量还小时，无法放入，状态直接保持不变）
        for (int j = T; j >= w; j--) {
            // 决策核心：我们在“不采摘当前草药”（保持原有的最优值 dp[j]）
            // 和“采摘当前草药”（上一轮尚未被更新的旧状态 dp[j - w] 加上当前草药价值 v）中取最大值
            dp[j] = std::max(dp[j], dp[j - w] + v);
        }
    }

    // dp[T] 即为在总时间 T 限制下的最大总价值
    std::cout << dp[T] << std::endl;
    return 0;
}
