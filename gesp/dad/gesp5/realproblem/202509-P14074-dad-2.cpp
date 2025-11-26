/*
 * P14074 [GESP202509 五级] 有趣的数字和
 * 题目要求：计算 [l, r] 区间内二进制表示中包含奇数个 1 的整数之和。
 * 算法：数位 DP
 */

#include <iostream>

typedef long long ll;

// Result 结构体用于存储 DP 的结果
struct Result {
    ll cnt;  // 满足条件的数的个数
    ll sum;  // 满足条件的数的和
};

// digits 存储数字 n 的二进制每一位，digits[0] 是最低位
int digits[40];
// memo 用于记忆化搜索，memo[pos][parity] 表示处理到第 pos 位，当前 1
// 的个数奇偶性为 parity 时的结果 parity = 0 表示偶数个 1，parity = 1 表示奇数个
// 1
Result memo[40][2];

// dfs 函数进行数位 DP
// pos: 当前处理的二进制位（从高位到低位）
// parity: 当前已经确定的高位中 1 的个数的奇偶性（0 为偶，1 为奇）
// limit: 是否受到上界限制。true 表示当前位只能取 0 到 digits[pos]，false
// 表示可以取 0 或 1
Result dfs(int pos, int parity, bool limit) {
    // 递归边界：处理完所有位（pos < 0）
    if (pos == -1) {
        // 如果最终 1 的个数是奇数（parity == 1），则这是一个“有趣的数”
        if (parity == 1) {
            return {1, 0};  // 返回个数 1，和 0（因为具体的数值在回溯时计算）
        } else {
            return {0, 0};  // 不是有趣的数
        }
    }
    // 记忆化搜索：如果不再受限且已经计算过，直接返回结果
    if (!limit && memo[pos][parity].cnt != -1) {
        return memo[pos][parity];
    }

    // 确定当前位的枚举上限
    int up = limit ? digits[pos] : 1;
    Result res = {0, 0};

    // 枚举当前位可能的取值 i (0 或 1)
    for (int i = 0; i <= up; i++) {
        // 递归处理下一位
        // pos - 1: 下一位
        // parity ^ i: 更新奇偶性。如果 i=0，奇偶性不变；如果 i=1，奇偶性翻转
        // limit && (i == up):
        // 更新限制状态。只有当前受限且选了上限，下一位才继续受限
        Result sub = dfs(pos - 1, parity ^ i, limit && (i == up));

        // 累加符合条件的数的个数
        res.cnt += sub.cnt;

        // 计算当前位对和的贡献
        // 当前位的值是 i * 2^pos
        ll cur_val = (ll)i << pos;
        // 当前位贡献的总和 = 当前位的值 * 后续满足条件的数的个数 +
        // 后续满足条件的数的和
        res.sum += sub.sum + cur_val * sub.cnt;
    }

    // 如果不受限，记录结果到 memo
    if (!limit) {
        memo[pos][parity] = res;
    }

    return res;
}

// solve 函数计算 [0, n] 范围内有趣的数的和
ll solve(ll n) {
    int len = 0;
    // 将 n 转换为二进制存入 digits 数组
    while (n) {
        digits[len] = n & 1;
        n >>= 1;
        len++;
    }
    // 初始化 memo 数组为 -1，表示未计算
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 2; j++) {
            memo[i][j].cnt = -1;
        }
    }
    // 从最高位开始 DFS
    // 初始 limit 为 true，因为最高位受 n 的限制
    // 初始 parity 为 0，因为还没选任何 1
    return dfs(len - 1, 0, true).sum;
}

int main() {
    // 定义左右边界 l 和 r，使用 long long 防止溢出
    ll l, r;
    std::cin >> l >> r;
    // 利用前缀和思想：[l, r] 的和 = solve(r) - solve(l - 1)
    std::cout << solve(r) - solve(l - 1) << std::endl;
    return 0;
}