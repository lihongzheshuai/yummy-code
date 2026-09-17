/**
 * 题目: 【GESP】C++一级真题 luogu-B4355 [GESP202506 一级] 值日
 * 题号: B4355
 * 归属: GESP1级 (202506认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b4355/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 声明变量n和m用于存储输入的两个值日周期
    int n,m;
    // 从标准输入读取两个整数
    std::cin >> n >> m;
    // 找出两个周期中的较大值作为循环起点
    int big = n > m ? n : m;
    // 从较大值开始循环，直到找到符合条件的天数
    for (int i = big; ;i++) {
        // 如果当前天数能同时被两个周期整除，说明是他们再次同时值日的日子
        if (i % n == 0 && i % m == 0) {
            // 输出结果并结束循环
            std::cout << i;
            break;
        }
    }
    return 0;
}
