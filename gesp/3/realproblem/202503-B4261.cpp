/**
 * 题目: 【GESP】C++三级真题 luogu-B4261 [GESP202503 三级] 2025
 * 题号: B4261
 * 归属: GESP3级 (202503认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b4261/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 声明变量x用于存储输入值
    int x;
    // 从标准输入读取x的值
    std::cin >> x;
    // 标记是否找到满足条件的y
    bool flag = false;
    // y从0开始尝试
    int y = 0;
    // 循环尝试所有可能的y值，直到2025（根据题目条件）
    while (y <= 2025) {
        // 检查是否满足 (x AND y) + (x OR y) = 2025
        if ((x & y) + (x | y) == 2025) {
            // 找到满足条件的y，设置标记为true
            flag = true;
            break;
        }
        y++;
    }
    // 根据是否找到满足条件的y输出结果
    if (flag) {
        // 找到则输出y的值
        std::cout << y;
    } else {
        // 未找到则输出-1
        std::cout << "-1";
    }
    return 0;
}
