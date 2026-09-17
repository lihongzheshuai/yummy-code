/**
 * 题目: 【GESP】C++五级练习（贪心思想考点） luogu-P9532 [YsOI2023] 前缀和
 * 题号: P9532
 * 归属: GESP5级
 * 博客: https://www.coderli.com/gesp-5-luogu-p9532/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n, x;
        std::cin >> n >> x;

        // 特判 x=1 的情况
        // 如果 x=1，由于所有数字都是正整数，k 只能为 1。
        // 序列只能是 1, 1, 2, 4...
        // a[n] = 1 * 2^(n-2)
        if (x == 1) {
            // pow 返回 double，对于大数可能丢失精度，但在题目范围内 (2^18)
            // 是安全的。 更严谨的写法是使用位运算：(1LL << (n - 2))
            std::cout << (long long)std::pow(2, n - 2) << std::endl;
            continue;
        }

        // 特判 n <= 2 的情况
        // 如果 n=1，a[1]=x。
        // 如果 n=2，a[2]=x (因为 a[2]=a[1]，若 x 在数组中，最小 a[2] 就是 x)。
        if (n <= 2) {
            std::cout << x << std::endl;
            continue;
        }

        // 计算 x 中包含多少个因子 2，记为 cnt。
        // 同时将 x 除以这些因子 2，剩下的 x 即为 k 的奇数部分 (odd_part)。
        int cnt = 0;
        while (x % 2 == 0) {
            cnt++;
            x /= 2;
        }

        // power 取 max(cnt, n-2)。
        int power = std::max(cnt, n - 2);

        // 输出结果
        // 使用 long long 防止溢出
        std::cout << (long long)std::pow(2, power) * x << std::endl;
    }
    return 0;
}
