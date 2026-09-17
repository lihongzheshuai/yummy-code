/**
 * 题目: 【GESP】C++一级真题 luogu-B4355 [GESP202506 一级] 值日
 * 题号: B4355
 * 归属: GESP1级 (202506认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b4355/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <numeric>

int main() {
    // 声明整型变量n和m，用于存储两个人的值日周期
    int n,m;
    // 从标准输入读取两个值日周期
    std::cin >> n >> m;
    // 使用C++标准库的lcm函数计算最小公倍数并输出
    std::cout << std::lcm(n,m);
    // 程序正常结束
    return 0;
}
