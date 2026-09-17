/**
 * 题目: 【CSP】CSP-J 2025真题 | 异或和 luogu-P14359 （相当于GESP六级水平）
 * 题号: P14359
 * 归属: GESP6级
 * 博客: https://www.coderli.com/csp-j-2025-p14359/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>
#include <vector>

const int MAX_VAL = 1 << 20;  // 2^20 = 1048576, 题目限制 a_i < 2^20, k < 2^20
int max_dp[MAX_VAL];

int main() {

    // 优化 I/O 速度，避免大量输入输出导致超时
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int k;
    std::cin >> n >> k;

    // 初始化 max_dp 数组
    // max_dp[v] 存储的是：当某个位置的前缀异或和为 v
    // 时，该位置及之前能得到的最大区间数
    for (int i = 0; i < MAX_VAL; ++i) {
        max_dp[i] = -1;
    }
    // 初始状态：还没有读取任何数时，前缀异或和为 0，区间数为 0
    max_dp[0] = 0;

    int current_xor = 0;  // 当前的前缀异或和 (pre[i])
    int dp = 0;           // 当前位置的最大区间数 (dp[i])

    for (int i = 1; i <= n; ++i) {
        int a;
        std::cin >> a;
        current_xor ^= a;  // 计算到当前位置 i 的前缀异或和

        // 步骤 A: 尝试以当前位置 i 作为区间的结尾
        // 我们需要找一个之前的断点 j-1，使得 pre[j-1] ^ pre[i] == k
        // 即 pre[j-1] == pre[i] ^ k
        int target = current_xor ^ k;

        // 如果之前存在某个位置的前缀异或和等于 target
        if (max_dp[target] != -1) {
            // 尝试以当前位置为结尾构成一个新区间
            // dp[i] = max(dp[i-1], max_dp[target] + 1)
            // 注意：这里的 dp 变量实际上在迭代过程中一方面代表
            // dp[i-1]，更新后代表 dp[i] 因为 dp[i] 至少是
            // dp[i-1]，所以直接比较即可
            dp = std::max(dp, max_dp[target] + 1);
        }

        // 更新当前前缀异或值的最大 dp 值
        // 如果当前 dp 值比之前记录的更大，则更新
        if (dp > max_dp[current_xor]) {
            max_dp[current_xor] = dp;
        }
    }

    std::cout << dp << std::endl;

    return 0;
}
