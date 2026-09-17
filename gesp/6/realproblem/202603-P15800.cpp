/**
 * 题目: 【GESP】C++六级真题 luogu-P15800, [GESP202603 六级] 选数
 * 题号: P15800
 * 归属: GESP6级 (202603认证真题)
 * 博客: https://www.coderli.com/gesp-6-luogu-p15800/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>


// 使用 long long 防止累加结果溢出
typedef long long ll;

const int MAXN = 100005;
ll a[MAXN];
int b[MAXN];
ll dp[MAXN * 2]; // 稍微开大一点防止越界

int main() {
    // 优化输入输出速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }

    // 从后往前计算 DP
    // dp 数组默认全为 0，dp[n+1] 开始往后都是 0，作为边界条件
    for (int i = n; i >= 1; i--) {
        // 下一个可以选择的位置
        // 注意：除了满足题目给出的 i + b[i]，还必须严格大于当前位置 i
        int next_idx = std::max(i + 1, i + b[i]);
        if (next_idx > n + 1) {
            next_idx = n + 1; // 越界部分当作 n + 1 处理，对应 dp 值为 0
        }

        // 状态转移：取“不选当前元素”和“选当前元素”的最大值
        dp[i] = std::max(dp[i + 1], a[i] + dp[next_idx]);
    }

    // dp[1] 即为在整个数组 1...n 中选择的最大和
    std::cout << dp[1] << "\n";

    return 0;
}
