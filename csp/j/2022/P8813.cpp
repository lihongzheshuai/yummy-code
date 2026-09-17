/**
 * 题目: 【CSP】CSP-J 2022真题 | 乘方 luogu-P8813 （适合GESP二级及以上考生练习）
 * 题号: P8813
 * 归属: GESP2级
 * 博客: https://www.coderli.com/csp-j-2022-p8813-power/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 优化输入输出流性能
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long a, b;
    std::cin >> a >> b;

    // 特判：如果底数 a 为 1，则 1 的任何次方都是 1，直接输出
    // 避免 b 很大时（如 10^9）循环超时
    if (a == 1) {
        std::cout << 1 << "\n";
        return 0;
    }

    long long ans = 1;
    bool overflow = false;

    // 模拟乘方过程
    for (int i = 1; i <= b; i++) {
        ans *= a;
        // 实时检查是否超过 10^9
        if (ans > 1000000000) {
            overflow = true;
            break;
        }
    }

    // 根据是否溢出输出对应结果
    if (overflow) {
        std::cout << -1 << "\n";
    } else {
        std::cout << ans << "\n";
    }

    return 0;
}
