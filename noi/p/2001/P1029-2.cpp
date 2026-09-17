/**
 * 题目: 【NOIP】2001真题解析 luogu-P1029 最大公约数和最小公倍数问题
 * 题号: P1029
 * 归属: 算法练习
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/noip-2001-luogu-p1029/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>

// 辗转相除法求最大公约数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x0, y0;
    std::cin >> x0 >> y0;

    // 前提判断：最小公倍数必须是最大公约数的倍数
    if (y0 % x0 != 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    long long product = (long long)x0 * y0; // P * Q = x0 * y0
    int count = 0;

    // 直接枚举 P，P 必须是 x0 的倍数
    for (long long p = x0; p * p <= product; p += x0) {
        if (product % p == 0) {
            long long q = product / p;
            // 直接验证 gcd(P, Q) 是否等于 x0
            if (gcd(p, q) == x0) {
                if (p == q) {
                    count += 1;
                } else {
                    count += 2;
                }
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}
