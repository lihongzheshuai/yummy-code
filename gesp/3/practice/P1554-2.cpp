/**
 * 题目: 【GESP】C++三级练习 luogu-P1554 梦中的统计
 * 题号: P1554
 * 归属: GESP3级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-p1554/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 定义变量m和n用于存储输入的区间范围
    int m, n;
    // 从标准输入读取m和n
    std::cin >> m >> n;
    // 定义长度为10的数组，用于统计0-9每个数字出现的次数
    int result[10] = {0};
    // 遍历区间[m,n]中的每个数
    for (int i = m; i <= n; i++) {
        // 将当前数字赋值给临时变量t
        int t = i;
        // 通过不断除以10取余的方式，分离数字的每一位
        while (t) {
            // t%10得到最低位数字，并在结果数组中对应位置加1
            result[t % 10]++;
            // 去掉最低位
            t /= 10;
        }
    }
    // 输出0-9每个数字出现的次数
    for (int i = 0; i < 10; i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}
