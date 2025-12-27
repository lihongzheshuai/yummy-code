#include <iostream>

/**
 * GESP 2025年12月 二级编程题 T1: 环保能量球
 *
 * 题目核心：
 * 1. 基础分：走 n 公里得 n 分。
 * 2. 奖励分：每走 x 公里额外得 1 分。
 *
 * 逻辑：总分 = n + (n / x)
 */

int main() {
    int t;
    std::cin >> t;  // 读取测试组数

    while (t--) {
        int n, x;
        std::cin >> n >> x;
        // n 公里基础能量 + (n/x) 公里奖励能量
        // C++ 整数除法自动向下取整，符合题目要求
        std::cout << n + (n / x) << std::endl;
    }

    return 0;
}