#include <iostream>

using namespace std;

// 快速幂函数，计算 (base^exp) % mod 的值。时间复杂度 O(log exp)
long long fastPow(long long base, long long exp, long long mod) {
    long long ans = 1;
    base = base % mod;  // 防止 base 初始就大于等于 mod 的情况，提前取模优化
    while (exp > 0) {
        // 如果当前指数的最低位（也就是二进制的末位）为 1，将当前权重下的 base
        // 乘入结果
        if (exp % 2 == 1) {
            ans = (ans * base) % mod;
        }
        // base 自乘，准备下一位的权重（即 a^1, a^2, a^4, a^8...）
        base = (base * base) % mod;
        exp = exp / 2;  // 指数除以 2（相当于二进制右移一位），处理下一位
    }
    return ans;
}

int main() {
    long long a, b, p;
    // 读入三个整数 a, b, p
    if (cin >> a >> b >> p) {
        // 调用快速幂算法求解
        long long result = fastPow(a, b, p);

        // 按照题目要求格式输出结果
        cout << a << "^" << b << " mod " << p << "=" << result << "\n";
    }
    return 0;
}