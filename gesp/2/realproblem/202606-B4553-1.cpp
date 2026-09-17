/**
 * 题目: 【GESP】C++二级真题 luogu-B4553 [GESP202606 二级] 完全平方数计数
 * 题号: B4553
 * 归属: GESP2级 (202606认证真题)
 * 解法: 解法 1 / 共 2 种解法
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
    // 计数器，记录完全平方数的个数
    int count = 0;
    // 遍历范围内的每个数
    for (int i = l; i <= r; i++) {
        // 对 i 开平方并取整
        int s = (int)std::sqrt(i);
        // 如果 s 的平方等于 i，则 i 是完全平方数
        if (s * s == i) {
            count++;
        }
    }
    // 输出完全平方数的个数
    std::cout << count << std::endl;
    return 0;
}
