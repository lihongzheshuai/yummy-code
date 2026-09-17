#include <algorithm>
#include <iostream>
#include <vector>

// 使用 long long 防止溢出，t 最大可达 10^16，累加和也会很大
typedef long long ll;

const int MAXN = 1000005;
ll d[MAXN];     // 存储问题难度
ll sum[MAXN];   // 难度的前缀和
ll cost[MAXN];  // 解决前 i 个问题的最小花费（即 sum 的前缀和）

int main() {
    // 优化 I/O 操作速度 (防止 TLE)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> d[i];
    }

    // 核心逻辑 1: 贪心
    // 为了让解决 k 个问题的总时间最少，我们应该：
    // 1. 选择难度最小的 k 个问题。
    // 2.
    // 在解决这k个问题时，把难度大的放在前面解决（乘数小），难度小的放在后面解决（乘数大）。
    //    具体推导：假设选了 k 个问题，难度从小到大排序为 a1, a2, ..., ak。
    //    第 1 个解决的问题耗时：1 * 难度
    //    第 i 个解决的问题耗时：i * 难度
    //    根据排序不等式，要使乘积之和最小，应该由小的系数乘大的难度，大的系数乘小的难度。
    //    即：1 * ak + 2 * ak-1 + ... + k * a1。
    //    这个式子等价于前缀和的前缀和。
    std::sort(d + 1, d + 1 + n);

    // 核心逻辑 2: 前缀和预处理
    // sum[i] = d[1] + ... + d[i]
    // cost[i] = sum[1] + ... + sum[i]
    //         = (d[1]) + (d[1]+d[2]) + ... + (d[1]+...+d[i])
    //         = i*d[1] + (i-1)*d[2] + ... + 1*d[i]
    // 这正好对应了解决前 i 个最小难度问题的最优总时间。
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + d[i];
        cost[i] = cost[i - 1] + sum[i];
    }

    // 处理询问
    for (int i = 0; i < q; i++) {
        ll t;
        std::cin >> t;

        // 核心逻辑 3: 二分查找 (手动实现)
        // 目标：找到满足 cost[x] <= t 的最大的 x
        // l: 可能解区间的左边界，r: 可能解区间的右边界，ans:
        // 记录当前找到的合法解
        ll l = 1, r = n, ans = 0;
        while (l <= r) {
            ll mid = l + (r - l) / 2;  // 防止 (l+r) 溢出
            if (cost[mid] <= t) {
                // 如果前 mid 个题也能做完，说明 mid 是一个可行解
                ans = mid;    // 记录这个可行解
                l = mid + 1;  // 尝试找更大的解，往右边搜
            } else {
                // 如果前 mid 个题做不完，说明 mid 太大了，答案肯定在左边
                r = mid - 1;
            }
        }
        std::cout << ans << "\n";
    }

    return 0;
}