/**
 * 题目: 【GESP】C++二级练习 luogu-B3638, 三角形面积
 * 题号: B3638
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3638/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    // 读取三个点的坐标
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    // 计算三个点之间的距离
    double a, b, c;
    a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); // 计算AB距离
    b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)); // 计算AC距离
    c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3)); // 计算BC距离
    // 计算三角形的半周长
    double tmp = (a + b + c) / 2;
    // 计算三角形的面积
    double s = sqrt(tmp * (tmp - a) * (tmp - b) * (tmp - c));
    // 输出三角形的面积
    printf("%.0f", s);
    return 0;
}
