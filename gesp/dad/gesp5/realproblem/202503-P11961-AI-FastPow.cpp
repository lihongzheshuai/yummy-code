/**
 * P11961 [GESP202503 五级] 原根判断 - 解法二
 *
 * 本解法特点：
 * 1. 严格遵守 C++11 标准，不使用 __int128 非标准扩展。
 * 2.
 * 利用"快速幂思想"实现"快速乘"（也称龟速乘），解决大数相乘取模可能溢出的问题。
 *    虽然本题 p <= 10^9，long long
 * 足够存储乘积，但快速乘是一种通用的处理大数取模的技巧。
 *
 * 算法核心：
 * - 快速乘：将 a * b 看作 b 个 a 相加，利用二进制拆分 b，将 O(b) 的加法优化为
 * O(log b)。
 * - 快速幂：利用二进制拆分指数，将 O(n) 的乘法优化为 O(log n)。
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 快速乘函数 (Binary Multiplication)
// 计算 (a * b) % mod
// 原理：类似于快速幂，将 b 写成二进制形式
// 例如 b = (101)_2 = 1*2^2 + 0*2^1 + 1*2^0
// a * b = a * (1*2^2 + 0*2^1 + 1*2^0) = a*2^2 + 0 + a*2^0
// 时间复杂度：O(log b)
long long mul_mod(long long a, long long b, long long mod) {
    long long result = 0;
    a %= mod;
    while (b > 0) {
        // 如果 b 的当前最低位是 1，则加上当前的 a
        if (b & 1) {
            result = (result + a) % mod;
        }
        // a 翻倍，对应二进制位的权重增加
        a = (a + a) % mod;
        // b 右移一位，处理下一位
        b >>= 1;
    }
    return result;
}

// 快速幂取模函数
// 计算 (base^exp) % mod
// 使用上面实现的 mul_mod 进行乘法运算，确保全程不溢出
// 时间复杂度：O((log exp) * (log mod)) —— 因为每次乘法是 O(log mod)
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            // 使用快速乘代替直接乘法
            result = mul_mod(result, base, mod);
        }
        // 使用快速乘代替直接乘法
        base = mul_mod(base, base, mod);
        exp >>= 1;
    }
    return result;
}

// 获取 n 的所有质因数
// 时间复杂度：O(sqrt(n))
vector<long long> get_prime_factors(long long n) {
    vector<long long> factors;
    // 处理因子 2
    if (n % 2 == 0) {
        factors.push_back(2);
        while (n % 2 == 0) {
            n /= 2;
        }
    }
    // 处理奇数因子
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    // 如果 n > 1，说明剩下的 n 本身就是一个质因数
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

// 判断 a 是否为 p 的原根
bool is_primitive_root(long long a, long long p) {
    // 条件 1: 1 < a < p
    if (a <= 1 || a >= p) {
        return false;
    }

    // 检查 a^(p-1) mod p = 1
    // 虽然题目保证 p 是质数，费马小定理保证成立，但作为完整性检查保留
    if (power_mod(a, p - 1, p) != 1) {
        return false;
    }

    // 获取 p-1 的所有质因数
    long long phi = p - 1;
    vector<long long> prime_factors = get_prime_factors(phi);

    // 条件 3 的等价判定：
    // 对于 p-1 的任意质因数 q，如果 a^((p-1)/q) mod p == 1，则 a 不是原根
    for (long long q : prime_factors) {
        if (power_mod(a, phi / q, p) == 1) {
            return false;
        }
    }

    return true;
}

int main() {
    // 优化输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (cin >> T) {
        while (T--) {
            long long a, p;
            cin >> a >> p;

            if (is_primitive_root(a, p)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}
