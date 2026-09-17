/**
 * 题目: 【GESP】C++二级练习 luogu-B2080, 计算多项式的值
 * 题号: B2080
 * 归属: GESP2级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b2080/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int n; // 定义整数变量n
    double x; // 定义浮点数变量x
    cin >> x >> n; // 从输入流中读取x和n的值
    double ans = 1; // 初始化答案为1
    ans += x * (1 - pow(x, n)) / (1 - x); // 使用等比数列求和公式计算答案
    printf("%.2f", ans); // 输出答案，保留两位小数
    return 0;
}
