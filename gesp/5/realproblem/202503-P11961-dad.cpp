/**
 * P11961 [GESP202503 五级] 原根判断
 *
 * 题目要求判断给定的整数 a 是否为质数 p 的原根。
 * 原根定义：
 * 1. 1 < a < p
 * 2. a^(p-1) mod p = 1
 * 3. 对于任意 1 <= i < p-1，a^i mod p != 1
 *
 * 算法思路：
 * 根据数论定理，a 是 p 的原根当且仅当对于 p-1 的所有质因数 q，
 * 都有 a^((p-1)/q) mod p != 1。
 *
 * 时间复杂度：O(sqrt(p) + k * log(p))，其中 k 是 p-1 的质因数个数。
 */

#include <algorithm>
#include <iostream>
#include <vector>

// 快速幂取模函数
// 计算 (base^exp) % mod
// 使用 long long 防止中间结果溢出
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        // 如果指数是奇数，将当前的 base 乘入结果
        if (exp & 1) {
            result = result * base % mod;
        }
        // base 自乘，指数右移一位（除以 2）
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    // 优化 I/O 操作
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        int a, p;
        std::cin >> a >> p;

        // 条件 1: 1 < a < p，题目数据自然满足
        // 条件 2: 费马小定理：如果 p 是质数，则 a^(p-1) mod p = 1
        // 恒成立，题目保证 p 是质数，自然满足，无需额外判断。

        // 条件 3 的等价判定：
        // 对于 p-1 的任意质因数 q，如果 a^((p-1)/q) mod p == 1，则 a 不是原根。
        // 这种方法比枚举所有 1 <= i < p-1 更高效。
        int target = p - 1;
        std::vector<int> primes;

        // 分解质因数：找出 p-1 的所有不同质因数
        for (int i = 2; i * i <= target; i++) {
            if (target % i == 0) {
                primes.push_back(i);
                // 除尽当前的质因子 i
                while (target % i == 0) {
                    target /= i;
                }
            }
        }
        // 如果 target > 1，说明剩下的 target 本身就是一个质因数
        if (target > 1) {
            primes.push_back(target);
        }

        bool flag = true;
        // 遍历 p-1 的所有质因数 q
        for (int q : primes) {
            // 计算指数 (p-1)/q
            int tmp = (p - 1) / q;
            // 检查 a^((p-1)/q) % p 是否等于 1
            // 如果等于 1，说明存在更小的指数使得同余 1 成立，违反原根定义
            if (power_mod(a, tmp, p) == 1) {
                flag = false;
                break;
            }
        }

        if (flag) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }

    return 0;
}
