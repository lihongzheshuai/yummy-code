/**
 * 题目: 【GESP】C++二级练习 luogu-B3709 [语言月赛202302]  最澄澈的空与海
 * 题号: B3709
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3709/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 定义变量n
    cin >> n; // 输入n的值
    long long factorial = 1; // 初始化阶乘为1
    if (n != 0) {
        for (int i = 1; i <= n; i++) {
            factorial *= i; // 计算n的阶乘
        }
    }
    for (long long z = 1; ; z++) { // 从1开始无限循环
        if (z == 1) {
            if (n == 1) {
                cout << 1 << " " << 0 << " " << 1 << endl; // 输出特殊情况的结果
                break; // 跳出循环
            } else {
                continue; // 继续下一轮循环
            }
        } else {
            long long numerator = z * (factorial - n); // 计算分子
            if (numerator % (z - 1) == 0) {
                long long x = numerator / (z - 1); // 计算x的值
                long long y = x - z * n; // 计算y的值
                cout << x << " " << y << " " << z << endl; // 输出结果
                break; // 跳出循环
            }
        }
    }
    return 0;
}
