/**
 * 题目: 【GESP】C++ 一级真题解析，[2025年12月，第十二次认证]第二题手机电量显示
 * 题号: 
 * 归属: GESP1级 (202512认证真题)
 * 博客: https://www.coderli.com/gesp-1-202512-2/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

/**
 * GESP 2025年12月 一级编程题 T2: 手机电量显示
 *
 * 题目核心：
 * 根据电量 P 进行分类显示：
 * 1. P <= 10: 显示 'R' (Red 警告)
 * 2. 10 < P <= 20: 显示 'L' (Low)
 * 3. P > 20: 直接显示数字 P
 */

int main() {
    int t;
    std::cin >> t;  // 读取测试数据组数

    while (t--) {
        int p;
        std::cin >> p;  // 读取当前电量百分比

        // 1. 电量非常低 (<= 10)
        if (p <= 10) {
            std::cout << "R" << std::endl;
        }
        // 2. 电量有点低 (10 < p <= 20)
        // 这里的 else if 隐含了 p > 10 的条件
        else if (p <= 20) {
            std::cout << "L" << std::endl;
        }
        // 3. 电量比较充足 (> 20)
        else {
            std::cout << p << std::endl;
        }
    }

    return 0;
}
