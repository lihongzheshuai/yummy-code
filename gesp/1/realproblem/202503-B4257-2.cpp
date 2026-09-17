/**
 * 题目: 【GESP】C++一级真题 luogu-B4257 [GESP202503 一级] 图书馆里的老鼠
 * 题号: B4257
 * 归属: GESP1级 (202503认证真题)
 * 解法: 解法 2 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b4257/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 定义变量存储书的数量(n)、啃一本书所需时间(x)和总时间(y)
    int n, x, y;
    // 从标准输入读取三个整数
    std::cin >> n >> x >> y;
    // 计算剩余完整的书的数量
    // 公式：总数 - 向上取整(总时间/单本时间)
    // (x + y - 1) / x 等价于 ceil(y/x)，用于向上取整
    std::cout << n - (x + y - 1) / x;
    return 0;
}
