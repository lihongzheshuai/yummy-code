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
    if (!(std::cin >> n)) return 0;

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
    long long total_subsets =
        1;  // 2^i, 初始也就是 2^0 = 1 (对应处理第一个元素之前)

    // 用一个变量记录当前 DP 中可能达到的最大和，用于稍微优化循环边界
    int current_max_sum = 0;

    for (int i = 0; i < n; ++i) {
        int limit = a[i];

        // 2. 统计不合法方案数：即之前的子集和 <= a[i] 的情况
        // 因为题目要求 sum_others > max (即 a[i])，所以 <= a[i] 都是不合法的
        // 我们只需要统计 sum <= a[i] 的数量，因为 sum > a[i] 的自然合法 (且 sum
        // <= 5000 之外的也合法) 注意：我们 DP 数组只开到了 5000
        // (MAX_VAL)，所有和超过 5000 的子集 在 DP
        // 数组中虽然没有显式记录超过部分的和， 但我们在计算合法方案时是用
        // (总子集数 - 不合法子集数) 不合法子集一定满足 sum <= a[i] <=
        // 5000，所以一定在 DP 数组范围内被记录了。

        long long invalid_count = 0;
        int check_limit = limit;
        if (check_limit >= MAX_VAL) check_limit = MAX_VAL - 1;

        for (int s = 0; s <= check_limit; ++s) {
            invalid_count = (invalid_count + dp[s]) % MOD;
        }

        // 3. 计算以 a[i] 为最大边的贡献
        // 贡献 = (当前前缀的总子集数 - 不合法的子集数)
        long long contribution = (total_subsets - invalid_count + MOD) % MOD;

        ans = (ans + contribution) % MOD;

        // 4. 更新 DP 数组，加入 a[i]
        // 类似于 0/1 背包，从大到小更新
        // 更新范围：从 current_max_sum + a[i] 到 a[i]
        // 但受限于 MAX_VAL，我们只关心 <= 5000 的部分

        int next_max_sum = current_max_sum + limit;
        if (next_max_sum >= MAX_VAL) next_max_sum = MAX_VAL - 1;

        for (int j = next_max_sum; j >= limit; --j) {
            dp[j] = (dp[j] + dp[j - limit]) % MOD;
        }

        // 更新总子集数 * 2
        total_subsets = (total_subsets * 2) % MOD;

        // 更新当前最大和
        if (current_max_sum + limit < MAX_VAL) {
            current_max_sum += limit;
        } else {
            current_max_sum = MAX_VAL - 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
