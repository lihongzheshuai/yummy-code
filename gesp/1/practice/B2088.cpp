/**
 * 题目: 【GESP】C++一级练习 luogu-B2088, 计算书费
 * 题号: B2088
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2088/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    // 定义10个变量，分别用来记录每种图书的数量
    double a, b, c, d, e, f, g, h, j, k;
    // 读取每种图书的数量
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> j >> k;
    // 计算应付的总费用
    printf("%.1f", a * 28.9 + b * 32.7 + c * 45.6 + d * 78 + e * 35 + f * 86.2 +
                       g * 27.8 + h * 43 + j * 56 + k * 65);
    return 0;
}
