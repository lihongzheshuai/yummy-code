/**
 * 题目: 【NOIP真题】2005 采药 luogu-P1048 | 适用于 GESP6级 / CSP-J 练习
 * 题号: P1048
 * 归属: GESP六级 / CSP-J
 * 博客: https://www.coderli.com/gesp-6-luogu-p1048/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

using namespace std;

// 最大时间上限为 1000，数组预留安全裕量
const int MAXT = 1005;

// 一维滚动数组：dp[j] 表示在采药总时间不超过 j 的约束下，所能获得的最大草药总价值
int dp[MAXT];

int main() {
    int T, M;
    // 读入采药的总时间限制 T 和山洞中草药的数目 M
    cin >> T >> M;

    // 依次处理每一株草药（外层循环遍历物品）
    for (int i = 1; i <= M; ++i) {
        int w, v;
        // 读入当前草药采摘所耗费的时间 w 和草药自身的价值 v
        cin >> w >> v;

        // 0/1 背包空间优化的核心：倒序逆推可用时间容量 j
        // 必须从最大时间 T 倒序递减至当前草药的耗时 w
        // 倒序能严格保证计算 dp[j] 时，所引用的 dp[j - w] 依然是上一轮未放入当前草药的旧状态
        // 从而确保每株草药至多只被采摘一次
        for (int j = T; j >= w; --j) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    // 最终 dp[T] 即为在总时间 T 的限制下能够采得的最大草药总价值
    cout << dp[T] << "\n";

    return 0;
}
