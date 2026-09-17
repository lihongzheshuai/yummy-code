/**
 * 题目: 【GESP】C++五级/四级练习（双指针/数学） luogu-P1147 连续自然数和
 * 题号: P1147
 * 归属: GESP4级
 * 解法: 解法 3 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-p1147/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cmath>

int main() {
    int m;
    std::cin >> m;

    // 根据公式推导，k 的最大值约为 sqrt(2*M)
    // 为了让首项 a 从小到大输出，我们需要让 k 从大到小枚举
    for (int k = sqrt(2 * m); k >= 2; --k) {
        // 判断是否构成整数解
        // 2M = k * (2a + k - 1)
        // 所以 2M 必须能被 k 整除
        long long double_m = 2LL * m;
        if (double_m % k == 0) {
            long long val = double_m / k;
            // val = 2a + k - 1
            // 2a = val - k + 1
            long long two_a = val - k + 1;

            // 2a 必须是偶数，且 a 必须大于 0
            if (two_a % 2 == 0 && two_a > 0) {
                int a = two_a / 2;
                std::cout << a << " " << a + k - 1 << std::endl;
            }
        }
    }

    return 0;
}
