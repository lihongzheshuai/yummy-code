/**
 * 题目: 【CSP】CSP-X 2018真题 | 小明的照片 luogu-B4072 （适合GESP一级及以上考生练习）
 * 题号: B4072
 * 归属: GESP1级
 * 博客: https://www.coderli.com/csp-x-2018-b4072/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int n, x, y, z;
    std::cin >> n >> x >> y >> z;

    // 直接计算差值，用连续减法避免中间结果溢出
    std::cout << n - x - y - z << std::endl;

    return 0;
}
