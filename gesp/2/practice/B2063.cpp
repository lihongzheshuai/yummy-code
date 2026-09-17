/**
 * 题目: 【GESP】C++二级练习 luogu-B2063 人口增长问题
 * 题号: B2063
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b2063/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int x, n; // 定义变量x和n
    cin >> x >> n; // 读取输入的x和n
    double ans = pow(1.001, n) * x ; // 计算答案
    printf("%.4f", ans); // 输出答案，保留4位小数
    return 0;
}
