/**
 * 题目: 【GESP】C++五级真题（数论考点） luogu-B3871 [GESP202309 五级] 因数分解
 * 题号: B3871
 * 归属: GESP5级 (202309认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-b3871/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

int main() {
    long long N;                // 读入待分解的正整数
    std::cin >> N;
    bool flag = false;          // 标记是否已输出过因子，用于控制乘号

    // 试除法枚举 2~√N 的所有可能因子
    for (long long i = 2; i <= std::sqrt(N); i++) {
        if (N % i == 0) {       // i 是 N 的一个质因子
            int count = 0;      // 统计该质因子出现的次数
            while (N % i == 0) {
                count++;
                N /= i;         // 将 i 完全除掉
            }
            if (flag) {
                std::cout << " * "; // 输出乘号，左右各空一格
            }
            flag = true;
            std::cout << i;     // 输出质因子
            if (count > 1) {
                std::cout << "^" << count; // 指数形式
            }
        }
    }
    // 若剩余 N>1，则它本身为质数，直接输出
    if (N > 1) {
        if (flag) {
            std::cout << " * ";
        }
        std::cout << N;
    }
    return 0;
}
