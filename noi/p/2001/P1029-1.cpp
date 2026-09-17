/**
 * 题目: 【NOIP】2001真题解析 luogu-P1029 最大公约数和最小公倍数问题
 * 题号: P1029
 * 归属: 算法练习
 * 解法: 解法 1 / 共 2 种解法
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

    int k = y0 / x0; // 将问题转化为在 k 的因数中寻找互质对
    int count = 0;

    // 枚举 k 的因数，只需枚举到 sqrt(k)
    for (int a = 1; a * a <= k; a++) {
        if (k % a == 0) {
            int b = k / a;
            // 判断因数对 (a, b) 是否互质
            if (gcd(a, b) == 1) {
                if (a == b) {
                    count += 1; // a == b 时只有一种方案
                } else {
                    count += 2; // (a, b) 和 (b, a) 是两种不同方案
                }
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}
