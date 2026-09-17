/**
 * 题目: 【GESP】C++三级练习 luogu-P1554 梦中的统计
 * 题号: P1554
 * 归属: GESP3级
 * 解法: 解法 1 / 共 2 种解法
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
        // 将数字转换为字符串，便于分离每一位
        std::string s = std::to_string(i);
        // 遍历字符串的每一位
        for (int j = 0; j < s.length(); j++) {
            // 将字符转换为对应的数字并在结果数组中计数
            result[s[j] - '0']++;
        }
    }

    // 输出0-9每个数字出现的次数
    for (int i = 0; i < 10; i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}
