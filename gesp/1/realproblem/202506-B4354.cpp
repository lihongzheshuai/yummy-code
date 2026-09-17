/**
 * 题目: 【GESP】C++一级真题 luogu-B4354 [GESP202506 一级] 假期阅读
 * 题号: B4354
 * 归属: GESP1级 (202506认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b4354/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 声明变量存储书的页数、每天最多阅读页数和假期天数
    int n, k, t;
    // 从标准输入读取三个整数
    std::cin >> n >> k >> t;
    // 计算假期总共能读的最大页数
    int pages = t * k;
    // 如果计算出的页数超过书的总页数
    if (pages > n) {
        // 输出书的总页数（因为不可能读超过书的总页数）
        std::cout << n;
    } else {
        // 否则输出计算出的最大可读页数
        std::cout << pages;
    }
    return 0;
}
