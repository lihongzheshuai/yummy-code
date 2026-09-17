/**
 * 题目: 【GESP】C++三级练习 luogu-B2091 向量点积计算
 * 题号: B2091
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2091/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 声明变量n用于存储向量维度
    int n;
    // 输入向量维度
    std::cin >> n;
    // 声明两个数组用于存储两个向量的分量
    int ary_1[n];
    int ary_2[n];
    // 输入第一个向量的所有分量
    for (int i = 0; i < n; i++) {
        std::cin >> ary_1[i];
    }
    // 输入第二个向量的所有分量
    for (int i = 0; i < n; i++) {
        std::cin >> ary_2[i];
    }
    // 初始化sum变量用于存储点积结果
    int sum = 0;
    // 计算两个向量的点积
    for (int i = 0; i < n; i++) {
        sum += ary_1[i] * ary_2[i];
    }
    // 输出点积结果
    std::cout << sum;
    return 0;
}
