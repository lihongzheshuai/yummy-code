/**
 * 题目: 【GESP/CSP练习】GESP五级 / CSP-J 题解：luogu-P1075 [NOIP2012 普及组] 质因数分解
 * 题号: P1075
 * 归属: GESP5级 / CSP-J
 * 博客: https://www.coderli.com/gesp-5-luogu-p1075-prime-factorization/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

using namespace std;

int main() {
    // 读入正整数 n (数据规模保证 1 <= n <= 2 * 10^9)
    // 采用 64 位长整型 long long 存储，避免因 i * i 运算超出 32 位整型上限而导致溢出死循环
    long long n;
    cin >> n;

    // 根据初等数论与正整数唯一分解定理：
    // n 是两个不同质数 p 和 q 的乘积 (设 2 <= p < q)
    // 根据因数成对分布的对称性，较小的质数 p 必然满足：p <= sqrt(n)
    // 且 n 仅有 1, p, q, n 这 4 个因数
    // 任何大于 1 且能整除 n 的最小正整数，必然就是较小的质数 p
    // 因此从 i = 2 开始自小到大枚举因数
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            // 找到较小的质因数 i (即 p)
            // 则较大的质因数必然等于 n / i (即 q)
            // 直接输出较大的质数并结束程序
            cout << n / i << endl;
            return 0;
        }
    }

    return 0;
}
