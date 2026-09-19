/**
 * 题目: 【GESP/CSP练习】GESP五级 / CSP-J 题解：luogu-P1029 [NOIP2001 普及组] 最大公约数和最小公倍数问题
 * 题号: P1029
 * 归属: NOIP 2001 普及组 / GESP5级
 * 博客: https://www.coderli.com/gesp-5-luogu-p1029-gcd-lcm/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

using namespace std;

// 欧几里得算法（辗转相除法）求最大公约数
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    long long x0, y0;
    cin >> x0 >> y0;

    // 若最小公倍数不能被最大公约数整除，则不存在合法的正整数对 (P, Q)
    if (y0 % x0 != 0) {
        cout << 0 << endl;
        return 0;
    }

    // 令 M = y0 / x0 = a * b，其中 P = a * x0, Q = b * x0 且 gcd(a, b) = 1
    long long m = y0 / x0;
    long long ans = 0;

    // 枚举 a 从 1 到 sqrt(M)
    for (long long a = 1; a * a <= m; ++a) {
        if (m % a == 0) {
            long long b = m / a;
            // 判定 a 与 b 是否互质
            if (gcd(a, b) == 1) {
                if (a == b) {
                    ans += 1;
                } else {
                    ans += 2; // (a, b) 与 (b, a) 是两种不同的有序对
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
