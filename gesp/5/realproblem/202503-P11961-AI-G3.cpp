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

using namespace std;

// 快速幂取模函数
// 计算 (base^exp) % mod
// 使用 __int128 防止中间结果溢出
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (long long)((__int128)result * base % mod);
        }
        base = (long long)((__int128)base * base % mod);
        exp >>= 1;
    }
    return result;
}

// 获取 n 的所有质因数
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

    // 费马小定理：如果 p 是质数，则 a^(p-1) mod p = 1 恒成立
    // 这里作为一个基本检查，虽然题目保证 p 是质数，但检查一下也无妨
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
