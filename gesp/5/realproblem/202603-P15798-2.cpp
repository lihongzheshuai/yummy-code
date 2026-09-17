/**
 * 题目: 【GESP】C++五级真题 luogu-P15798, [GESP202603 五级] 有限不循环小数
 * 题号: P15798
 * 归属: GESP5级 (202603认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-p15798/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    long long L, R;
    std::cin >> L >> R;

    int ans = 0; // 用于统计符合要求的"终止数"的个数

    // 外层循环枚举 2 的幂次，变量 p2 用来存放 2^x 的值
    // p2 不断乘以 2，直到超出 R 的最大范围
    for (long long p2 = 1; p2 <= R; p2 *= 2) {

        // 内层循环枚举 5 的幂次，变量 p5 用来存放 5^y 的值
        // p5 不断乘以 5，同时我们要确保 p2 * p5 的总积不能超过 R
        for (long long p5 = 1; p2 * p5 <= R; p5 *= 5) {

            // 组装出当前的 a 值
            long long a = p2 * p5;

            // 如果这个生成的 a 值刚好落在 [L, R] 范围内，计数加一
            if (a >= L && a <= R) {
                ans++;
            }
        }
    }

    // 最终输出满足条件的数量
    std::cout << ans << std::endl;

    return 0;
}
