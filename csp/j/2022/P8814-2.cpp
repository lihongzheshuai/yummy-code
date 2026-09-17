/**
 * 题目: 【CSP】CSP-J 2022真题 | 解密 luogu-P8814 （适合GESP四级及以上考生练习）
 * 题号: P8814
 * 归属: GESP4级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/csp-j-2022-p8814-decode/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

void solve() {
    long long n, d, e;
    std::cin >> n >> d >> e;

    // 根据推导，m = p + q
    long long m = n - e * d + 2;

    // 二分区间 p <= q，且 p + q = m，因此 p 必然在 [1, m / 2]
    long long L = 1, R = m / 2;
    long long p = -1;

    while (L <= R) {
        long long mid = L + (R - L) / 2;
        long long val = mid * (m - mid);

        if (val == n) {
            p = mid;
            break; // 找到答案，退出二分
        } else if (val < n) {
            L = mid + 1; // 乘积偏小，增大 p
        } else {
            R = mid - 1; // 乘积偏大，减小 p
        }
    }

    // 如果没有找到解
    if (p == -1) {
        std::cout << "NO\n";
    } else {
        long long q = m - p;
        std::cout << p << " " << q << "\n";
    }
}

int main() {
    // 优化输入输出流性能
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k;
    std::cin >> k;
    while (k--) {
        solve();
    }

    return 0;
}
