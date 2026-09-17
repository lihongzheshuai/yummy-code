/**
 * 题目: 【GESP】C++二级真题 luogu-B4554 [GESP202606 二级] 菱形
 * 题号: B4554
 * 归属: GESP2级 (202606认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b4554/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cmath>

int main() {
    // 读入菱形的边长
    int n;
    std::cin >> n;
    // 网格大小为 (2n-1) x (2n-1)
    int size = 2 * n - 1;
    // 菱形中心位置（行列下标均为 n-1）
    int center = n - 1;
    // 遍历每一行
    for (int i = 0; i < size; i++) {
        // 遍历每一列
        for (int j = 0; j < size; j++) {
            // 计算当前位置到中心的曼哈顿距离
            // 若距离恰好等于 n-1，则该位置是菱形边上的点
            if (std::abs(i - center) + std::abs(j - center) == n - 1) {
                std::cout << "+";
            } else {
                std::cout << ".";
            }
        }
        // 每行结束后换行
        std::cout << std::endl;
    }
    return 0;
}
