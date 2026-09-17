/**
 * 题目: 【GESP】C++一级真题 luogu-B4257 [GESP202503 一级] 图书馆里的老鼠
 * 题号: B4257
 * 归属: GESP1级 (202503认证真题)
 * 解法: 解法 1 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b4257/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 定义变量存储书的数量、啃一本书所需时间和总时间
    int n, x, y;
    // 从标准输入读取三个整数
    std::cin >> n >> x >> y;
    // 计算剩余完整的书的数量
    // 如果总时间能被啃一本书的时间整除，说明最后一本书已经被啃完
    if (y % x == 0) {
        std::cout << n - y / x;
    }
    // 如果不能整除，说明最后一本书正在被啃，也要算作不完整
    else {
        std::cout << n - y / x - 1;
    }
    return 0;
}
