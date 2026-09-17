/**
 * 题目: 【CSP】CSP-J 2025真题 | 多边形 luogu-P14360 （相当于GESP六级水平）
 * 题号: P14360
 * 归属: GESP6级
 * 博客: https://www.coderli.com/csp-j-2025-p14360/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>
#include <vector>

const int MOD = 998244353;
const int MAX_VAL = 5005;  // a_i 最大值是 5000

int dp[MAX_VAL];  // dp[s] 表示当前已处理的小木棍中，和为 s 的子集数量

int main() {
    // 优化 I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // 1. 排序：从小到大处理，保证处理 a[i] 时，它就是当前子集的最大值
    std::sort(a.begin(), a.end());

    // 初始化 DP
    // dp[0] = 1 (空集和为0)
    for (int i = 0; i < MAX_VAL; ++i) dp[i] = 0;
    dp[0] = 1;

    long long ans = 0;
    long long total_subsets = 1;  // 2^i, 初始也就是 2^0 = 1 (对应处理第一个元素之前)

    for (int i = 0; i < n; ++i) {
        int limit = a[i];

        // 2. 统计 “不合法” 的方案数
        // 所谓不合法，就是“除去最大边 a[i] 后，其余边之和 <= a[i]”。
        // 我们之前维护的 dp[s] 就是 sum=s 的方案数。
        // 所以我们把 s 从 0 到 a[i] 的所有 dp[s] 累加起来。

        long long invalid_count = 0;

        // 细节：循环上界取 limit (也就是 a[i])。
        // 虽然 dp 数组最大只有 5005，但 a[i] 最大也就 5000，不会越界。
        // 一般为了严谨会写 min(limit, MAX_VAL - 1)，但本题数据范围保证 limit < MAX_VAL。
        for (int s = 0; s <= limit; ++s) {
            // 累加所有满足 "其他边之和 s <= 最大边 a[i]" 的情况
            // 这些情况都无法与 a[i] 组成多边形
            invalid_count = (invalid_count + dp[s]) % MOD;
        }

        // 3. 计算以 a[i] 为最大边的贡献 (核心 MOD 运算逻辑)
        // 公式：贡献 = 总子集数 - 不合法数
        // C++ 中取模的坑：(A - B) % P 可能会变成负数！
        // 比如 (2 - 5) % 10 = -3，但我们需要的是正余数 7。
        // 解决方法：((A - B) % P + P) % P，或者简化为 (A - B + P) % P。
        long long contribution = (total_subsets - invalid_count + MOD) % MOD;

        // 根据模运算性质，每一步加减乘结果取模，最终结果依然正确
        ans = (ans + contribution) % MOD;

        // 4. 更新 DP 数组，加入 a[i]
        // 核心逻辑：类似于 0/1 背包，必须**从大到小**更新
        // 为什么？因为 dp[j] = dp[j] + dp[j - limit]
        // 我们希望右边的 dp[j - limit] 是**上一轮**（还没加入 a[i] 时）的值。
        // 如果从小到大更新，dp[j - limit] 可能已经被更新过（包含了 a[i]），
        // 导致 a[i] 被重复使用（相当于完全背包），这违反了“每根木棍只能用一次”的规则。

        // 更新范围：从 MAX_VAL - 1 到 a[i]
        for (int j = MAX_VAL - 1; j >= limit; --j) {
            // 加法取模：(A + B) % P，防止溢出。
            dp[j] = (dp[j] + dp[j - limit]) % MOD;
        }

        // 更新总子集数 * 2
        // 逻辑：对于之前存在的每一个子集，现在都有“选 a[i]”和“不选 a[i]”两种情况
        // 所以子集总数翻倍。total_subsets 维护的是 2^i
        total_subsets = (total_subsets * 2) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}
