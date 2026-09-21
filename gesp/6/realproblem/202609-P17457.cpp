/**
 * 题目: 【GESP真题】GESP六级 / CSP-J 题解：luogu-P17457 [GESP202609 六级] 数组划分
 * 题号: P17457
 * 归属: GESP6级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-6-luogu-p17457-array-partition/
 * 算法: 线性动态规划 (DP) + 前缀和优化
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 * 作者: OneCoder
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 读入数组元素总数 n
    int n;
    cin >> n;

    // a 数组存储原始输入的 n 个整数 (下标采用 1 ~ n，方便对应前缀和)
    // prefix 数组存储前缀和，prefix[i] 表示前 i 项之和：a[1] + a[2] + ... + a[i]
    // 数据范围：n <= 2000，|a_i| <= 100，前缀和最大绝对值可达 2000 * 100 = 200,000
    // 子段和的平方最大可达 (200,000)^2 = 4 * 10^10，已超出 32 位 int 上限 (~2 * 10^9)
    // 为避免整型溢出，所有数值与 DP 状态统一使用 64 位整型 long long
    vector<long long> a(n + 1);
    vector<long long> prefix(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        // 递推计算前缀和，实现 O(1) 快速查询任意连续子段 [j+1, i] 的元素和
        prefix[i] = prefix[i - 1] + a[i];
    }

    // 定义无穷大常量 INF，用于初始化求最小值的 DP 数组
    // 答案上限约为 2000 * (200,000)^2 = 8 * 10^13，1e18 足够充当正无穷上界且不会溢出
    const long long INF = 1e18;

    // dp[i] 表示将前 i 个元素 a[1...i] 划分为若干个非空连续子段时的最小偏差值之和
    vector<long long> dp(n + 1, INF);

    // 初始状态 / 边界条件：
    // 前 0 个元素尚未划分任何子段，偏差值为 0
    dp[0] = 0;

    // 外层循环：依序计算前缀长度 i 从 1 到 n 的最小偏差值
    for (int i = 1; i <= n; ++i) {
        // 内层循环：枚举最后一个子段的起始位置 j+1（即上一个子段结束在 j 处，0 <= j < i）
        // 此时最后一段区间为 [j+1, i]，其子段和为 prefix[i] - prefix[j]
        for (int j = 0; j < i; ++j) {
            // O(1) 计算当前子段的元素和
            long long seg_sum = prefix[i] - prefix[j];
            // 计算按照位置 j 划分时的总偏差值：前 j 个元素的最优值 + 当前子段和的平方
            long long cost = dp[j] + seg_sum * seg_sum;

            // 状态转移：寻找所有合法划分点 j 中的最小值
            if (cost < dp[i]) {
                dp[i] = cost;
            }
        }
    }

    // 输出将整个数组 a[1...n] 划分为若干子段后的最小偏差值
    cout << dp[n] << endl;

    return 0;
}
