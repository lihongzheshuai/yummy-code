/**
 * 题目: 【GESP】C++五级真题（数论考点） luogu-B3871 [GESP202309 五级] 因数分解
 * 题号: B3871
 * 归属: GESP5级 (202309认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-b3871/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <vector>
#include <iostream>
#include <cmath>

int main() {
    long long N;
    std::cin >> N;                          // 读入待分解的正整数
    std::vector<std::pair<long long, int>> factors; // 存储质因子及其指数

    // 试除法枚举 2~√N 的所有可能因子
    for (long long i = 2; i <= std::sqrt(N); i++) {
        if (N % i == 0) {                   // i 是 N 的一个质因子
            int count = 0;                  // 统计该质因子出现的次数
            while (N % i == 0) {            // 将 i 完全除掉
                count++;
                N /= i;
            }
            factors.push_back({i, count});  // 记录质因子及其指数
        }
    }
    // 若剩余 N>1，则它本身为质数，单独记录
    if (N > 1) {
        factors.push_back({N, 1});
    }

    // 按格式输出质因数分解式
    for (size_t i = 0; i < factors.size(); i++) {
        if (i > 0) {
            std::cout << " * ";             // 输出乘号，左右各空一格
        }
        std::cout << factors[i].first;      // 输出质因子
        if (factors[i].second > 1) {
            std::cout << "^" << factors[i].second; // 指数形式
        }
    }
    return 0;
}
