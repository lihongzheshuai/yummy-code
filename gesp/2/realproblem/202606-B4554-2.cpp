/**
 * 题目: 【GESP】C++二级真题 luogu-B4554 [GESP202606 二级] 菱形
 * 题号: B4554
 * 归属: GESP2级 (202606认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b4554/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 读入菱形的边长
    int n;
    std::cin >> n;
    // 网格大小为 (2n-1) x (2n-1)
    int size = 2 * n - 1;
    // 遍历每一行
    for (int i = 0; i < size; i++) {
        // 计算当前行到中心行的距离
        int dist;
        if (i < n) {
            dist = n - 1 - i;
        } else {
            dist = i - (n - 1);
        }
        // 第 i 行的 '+' 出现在第 dist 列和第 size - 1 - dist 列
        for (int j = 0; j < size; j++) {
            if (j == dist || j == size - 1 - dist) {
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
