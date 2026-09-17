#include <iostream>

typedef long long ll;

// 快速幂函数，计算 (base^exp) % mod 的值。时间复杂度 O(log exp)
ll fastPow(ll base, ll exp, ll mod) {
    base = base % mod;  // 防止 base 初始就大于等于 mod 的情况，提前取模优化
    ll ans = 1;         // ans 用于记录最终的累乘结果，初始为 1
    while (exp > 0) {   // 只要指数还不为 0，就继续处理
        // 如果当前指数的最末位（二进制最低位）是 1
        // 说明当前权重下的 base 需要乘入最终结果
        if (exp & 1) {
            ans = (ans * base) % mod;
        }
        // 将底数自乘，对应二进制位左移，即 a^1 -> a^2 -> a^4 -> a^8 ...
        base = (base * base) % mod;
        // 指数右移一位，也就是除以 2，处理下一位二进制位
        exp >>= 1;
    }
    return ans;  // 返回最终计算结果
}

int main() {
    long long a, b, p;
    // 读入底数 a, 指数 b, 模数 p
    std::cin >> a >> b >> p;

    // 调用快速幂算法求解 a^b mod p
    long long result = fastPow(a, b, p);

    // 按照题目要求格式输出结果："a^b mod p=s"
    std::cout << a << "^" << b << " mod " << p << "=" << result << "\n";
    return 0;
}