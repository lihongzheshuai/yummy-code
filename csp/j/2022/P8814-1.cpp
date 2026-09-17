/**
 * 题目: 【CSP】CSP-J 2022真题 | 解密 luogu-P8814 （适合GESP四级及以上考生练习）
 * 题号: P8814
 * 归属: GESP4级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/csp-j-2022-p8814-decode/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cmath>

void solve() {
    long long n, d, e;
    std::cin >> n >> d >> e;

    // 根据推导，m = p + q
    long long m = n - e * d + 2;

    // 计算判别式 delta = m^2 - 4n
    long long delta = m * m - 4 * n;

    // 如果判别式小于 0，无实数解
    if (delta < 0) {
        std::cout << "NO\n";
        return;
    }

    // 对方程求根，并校验是否为完全平方数
    long long r = std::round(std::sqrt(delta));
    if (r * r != delta) {
        std::cout << "NO\n";
        return;
    }

    // 校验分子是否为偶数，即是否能被 2 整除
    if ((m - r) % 2 != 0) {
        std::cout << "NO\n";
        return;
    }

    // 计算 p 和 q
    long long p = (m - r) / 2;
    long long q = (m + r) / 2;

    // 校验 p 和 q 是否为正整数
    if (p <= 0 || q <= 0) {
        std::cout << "NO\n";
        return;
    }

    std::cout << p << " " << q << "\n";
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
