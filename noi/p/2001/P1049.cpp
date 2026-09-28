/**
 * 题目: 【GESP/CSP练习】GESP六级 / CSP-J 题解：luogu-P1049 [NOIP2001 普及组] 装箱问题
 * 题号: P1049
 * 归属: GESP六级 / CSP-J / NOIP2001 普及组
 * 博客: https://www.coderli.com/gesp-6-luogu-p1049-packing-problem/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 箱子最大容量 V <= 20000，定义在全局静态存储区预留安全裕量
const int MAXV = 20005;

// 一维滚动数组：dp[j] 表示在当前容量限制为 j 的条件下，能够装入物品的最大总体积
int dp[MAXV];

int main() {
    int V, n;
    // 读入箱子总容量 V
    cin >> V;
    // 读入物品总数 n
    cin >> n;

    // 读入每个物品的体积
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    // 0/1 背包核心动态规划过程
    // 外层循环：逐一考察每一个物品
    for (int i = 0; i < n; ++i) {
        // 内层循环：逆序遍历背包容量 j（从最大容量 V 倒序递减至当前物品体积 v[i]）
        // 逆序遍历是 0/1 背包的关键：确保每个物品至多被使用一次
        for (int j = V; j >= v[i]; --j) {
            // 状态转移方程：比较不装该物品（dp[j]）与装入该物品（dp[j - v[i]] + v[i]）的体积
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
        }
    }

    // dp[V] 即为在容量为 V 时所能装入物品的最大总体积
    // 题目要求最小剩余空间，因此最终结果为总容量 V 减去装入的最大体积 dp[V]
    cout << V - dp[V] << "\n";

    return 0;
}
