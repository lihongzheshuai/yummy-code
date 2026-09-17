/**
 * 题目: 【GESP】C++一级真题 luogu-B4258 [GESP202503 一级] 四舍五入
 * 题号: B4258
 * 归属: GESP1级 (202503认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b4258/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 读取需要处理的整数个数
    int n;
    std::cin >> n;

    // 循环处理每个整数
    while (n--) {
        // 读取当前需要四舍五入的整数
        int x;
        std::cin >> x;

        // 获取个位数
        int last_num = x % 10;

        // 根据四舍五入规则处理
        if (last_num < 5) {
            // 小于5，向下取整到最近的整十数
            std::cout << x - last_num << std::endl;
        } else {
            // 大于等于5，向上取整到最近的整十数
            std::cout << x + (10 - last_num) << std::endl;
        }
    }
    return 0;
}
