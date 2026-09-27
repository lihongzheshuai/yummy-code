/**
 * 题目: 【GESP/CSP练习】GESP六级 / CSP-J 题解：luogu-P1616 疯狂的采药
 * 题号: P1616
 * 归属: GESP六级 / CSP-J
 * 博客: https://www.coderli.com/gesp-6-luogu-p1616-crazy-knapsack/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

using namespace std;

// 最大时间上限 t <= 10^7，全局开辟数组预留安全裕量
const int MAXT = 10000005;

// 一维滚动数组：dp[j] 表示在总耗时不超过 j 的情况下，能采得的草药最大总价值
// 易错提示：极限情况下总价值可达 10^7 * 10^4 = 10^11，超出 32 位 int 范围，必须使用 long long
long long dp[MAXT];

int main() {
    int t, m;
    // 读入能够用来采药的总时间 t 和山洞里的草药种类数 m
    cin >> t >> m;

    // 逐一处理每种草药（外层循环遍历物品种类）
    for (int i = 1; i <= m; ++i) {
        int cost, val;
        // 读入当前草药采摘耗时 cost 和其蕴含价值 val
        cin >> cost >> val;

        // 完全背包核心：正序遍历时间容量 j（从当前耗时 cost 到总时间 t）
        // 正序遍历能让较小容量的状态在当前这轮中先被更新
        // 当更新到较大容量时，所引用的 dp[j - cost] 已经包含了选取当前物品的收益
        // 这天然实现了同一种草药可以无限制地疯狂重复采摘
        for (int j = cost; j <= t; ++j) {
            dp[j] = max(dp[j], dp[j - cost] + val);
        }
    }

    // 最终 dp[t] 即为在规定的总时间 t 内能够采得的最大草药总价值
    cout << dp[t] << "\n";

    return 0;
}
