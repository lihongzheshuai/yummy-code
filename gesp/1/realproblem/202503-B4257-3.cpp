/**
 * 题目: 【GESP】C++一级真题 luogu-B4257 [GESP202503 一级] 图书馆里的老鼠
 * 题号: B4257
 * 归属: GESP1级 (202503认证真题)
 * 解法: 解法 3 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b4257/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>#include <iostream>
#include <cmath>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::cout << n - std::ceil((double)y / x);
    return 0;
}
