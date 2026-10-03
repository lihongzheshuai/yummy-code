/**
 * 题目: 【NOIP真题】2006 开心的金明 luogu-P1060 | 适用于 GESP6级 / CSP-J 练习
 * 题号: P1060
 * 归属: GESP六级 / CSP-J
 * 博客: https://www.coderli.com/gesp-6-luogu-p1060/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 总预算 N < 30000，定义在全局静态存储区，预留安全边界
const int MAXN = 30005;

// 一维滚动数组：dp[j] 表示在预算上限为 j 元时，能获得的最大“价格与重要度乘积”总和
int dp[MAXN];

int main() {
    // 优化标准输入输出流性能，加速大规模数据读写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    // 读入总钱数 n 与希望购买的物品总数 m
    if (!(cin >> n >> m)) {
        return 0;
    }

    // 0/1 背包动态规划过程
    // 逐一读入并处理每个物品，无需预先保存全部物品数组，节省内存空间
    for (int i = 0; i < m; ++i) {
        int v, p;
        cin >> v >> p;
        int value = v * p; // 当前物品的实际收益（价值）：价格 * 重要度

        // 逆序枚举当前预算 j（从总钱数 n 倒序递减至当前物品价格 v）
        // 核心机制：逆序遍历确保在更新 dp[j] 时，所引用的 dp[j - v] 来自上一轮未放入当前物品的状态，
        // 从而严格保证每件物品至多被选购一次（0/1 背包特性）
        for (int j = n; j >= v; --j) {
            dp[j] = max(dp[j], dp[j - v] + value);
        }
    }

    // dp[n] 即为在不超过 n 元预算的前提下，所能获得的最大乘积总和
    cout << dp[n] << "\n";

    return 0;
}
