/**
 * 题目: 【GESP】C++二级真题 luogu-B4553 [GESP202606 二级] 完全平方数计数
 * 题号: B4553
 * 归属: GESP2级 (202606认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b4553/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cmath>

int main() {
    // 定义输入的范围边界
    int l, r;
    // 从标准输入读取 l 和 r
    std::cin >> l >> r;
    // [1, r] 中完全平方数的个数为 floor(sqrt(r))
    // [1, l-1] 中完全平方数的个数为 floor(sqrt(l-1))
    // 两者相减即为 [l, r] 中完全平方数的个数
    int count = (int)std::sqrt(r) - (int)std::sqrt(l - 1);
    // 输出结果
    std::cout << count << std::endl;
    return 0;
}
