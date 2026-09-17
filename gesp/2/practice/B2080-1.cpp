/**
 * 题目: 【GESP】C++二级练习 luogu-B2080, 计算多项式的值
 * 题号: B2080
 * 归属: GESP2级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b2080/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n; // 定义整数变量n
    double x; // 定义浮点数变量x
    cin >> x >> n; // 从输入流中读取x和n的值
    double ans = 1; // 初始化答案为1
    for (int i = 1; i <= n; i++) { // 从1到n进行循环
        double power = pow(x,i); // 计算x的i次方
        ans += power; // 将当前项的值累加到答案中
    }
    printf("%.2f", ans); // 输出答案，保留两位小数
    return 0;
}
