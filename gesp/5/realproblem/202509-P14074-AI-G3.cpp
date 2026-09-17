/**
 * @file 202509-P14074-AI-G3.cpp
 * @brief P14074 [GESP202509 五级] 有趣的数字和
 *
 * 题目描述：
 * 如果一个正整数的二进制表示包含奇数个 1，那么这个正整数是有趣的。
 * 给定正整数 l, r，统计满足 l <= n <= r 的有趣的整数 n 之和。
 *
 * 解题思路：
 * 这是一个典型的数位 DP (Digit DP) 问题。
 * 我们需要计算区间 [l, r] 的和，可以转化为计算 solve(r) - solve(l - 1)，
 * 其中 solve(x) 计算 [1, x] 之间所有有趣的整数之和。
 *
 * 数位 DP 状态设计：
 * dp(pos, parity, limit)
 * - pos: 当前处理的二进制位（从高位到低位）。
 * - parity: 当前已经遇到的 1 的个数的奇偶性（0 为偶数，1 为奇数）。
 * - limit: 是否受到上界限制。
 *
 * 返回值：
 * 需要返回两个值：
 * 1. cnt: 满足条件的数的个数。
 * 2. sum: 满足条件的数的和。
 */

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

// 定义返回结构体，包含个数和总和
struct Result {
    ll cnt;  // 满足条件的数的个数
    ll sum;  // 满足条件的数的总和
};

// 记忆化数组
// pos 最大约为 30 (10^9 < 2^30)
// parity 只有 0 和 1 两种状态
Result memo[35][2];
int digits[35];  // 存储二进制位
int len;         // 二进制位数

/**
 * @brief 深度优先搜索进行数位 DP
 *
 * @param pos 当前处理的位（从高到低）
 * @param parity 当前 1 的个数的奇偶性 (0: 偶数, 1: 奇数)
 * @param limit 是否受到数值上界的限制
 * @return Result 包含满足条件的数的个数和总和
 */
Result dfs(int pos, int parity, bool limit) {
    // 递归边界：处理完所有位
    if (pos == -1) {
        // 如果 1 的个数是奇数，则为一个有效的“有趣数”
        // 返回 {1, 0} 表示找到 1 个数，其后缀和为 0 (因为没有更多位了)
        // 如果是偶数，则无效，返回 {0, 0}
        if (parity == 1)
            return {1, 0};
        else
            return {0, 0};
    }

    // 如果没有限制且已经计算过，直接返回记忆化的结果
    if (!limit && memo[pos][parity].cnt != -1) {
        return memo[pos][parity];
    }

    // 当前位能取的最大值
    int up = limit ? digits[pos] : 1;
    Result res = {0, 0};

    // 枚举当前位可能的取值 (0 或 1)
    for (int d = 0; d <= up; ++d) {
        // 递归调用下一位
        // pos - 1: 下一位
        // parity ^ d: 更新奇偶性。如果 d=0，奇偶性不变；如果 d=1，奇偶性翻转。
        // limit && (d == up): 更新限制状态
        Result sub = dfs(pos - 1, parity ^ d, limit && (d == up));

        if (sub.cnt > 0) {
            // 累加个数
            res.cnt += sub.cnt;

            // 计算当前位对总和的贡献
            // 当前位 d 在 pos 位置，代表的值是 d * 2^pos
            // 这个值会出现 sub.cnt 次
            // 所以贡献为 (d * 2^pos) * sub.cnt + sub.sum
            ll val = (ll)d << pos;
            res.sum += val * sub.cnt + sub.sum;
        }
    }

    // 如果没有限制，记录结果
    if (!limit) {
        memo[pos][parity] = res;
    }
    return res;
}

/**
 * @brief 计算 [1, n] 之间有趣的整数之和
 *
 * @param n 上界
 * @return ll 有趣的整数之和
 */
ll solve(ll n) {
    if (n == 0) return 0;
    len = 0;
    // 将 n 转换为二进制存储
    while (n) {
        digits[len++] = n % 2;
        n /= 2;
    }

    // 初始化记忆化数组
    // 注意：这里每次 solve 都重置，虽然对于无 limit 的状态是可以复用的，
    // 但为了简单起见和防止潜在问题，每次重置。数据范围较小，开销可忽略。
    for (int i = 0; i < 35; ++i) {
        for (int j = 0; j < 2; ++j) {
            memo[i][j].cnt = -1;
        }
    }

    // 从最高位开始 DFS
    return dfs(len - 1, 0, true).sum;
}

int main() {
    // 优化 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll l, r;
    if (cin >> l >> r) {
        // 答案是 [1, r] 的和减去 [1, l-1] 的和
        cout << solve(r) - solve(l - 1) << endl;
    }
    return 0;
}
