/**
 * 题目: 【GESP】C++二级练习 luogu-B2053 求一元二次方程
 * 题号: B2053
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b2053/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    double a, b, c; // 定义变量a, b, c
    cin >> a >> b >> c; // 读取输入的a, b, c
    double ee = b * b - 4 * a * c; // 计算判别式
    if (ee >= 0) { // 如果判别式非负，则方程有实根
        double d = sqrt(ee); // 计算根号判别式
        double e = d - b; // 计算x1的分子
        double x1 = e / (2 * a); // 计算x1
        double e_x2 = -1 * b - d; // 计算x2的分子
        double x2 = e_x2 / (2 * a); // 计算x2
        if (x1 == x2) { // 如果两个根相等
            printf("x1=x2=%.5f", x1); // 输出格式为x1=x2=aaaa
        } else { // 如果两个根不相等
            if (x1 > x2) { // 如果x1大于x2，则交换它们
                printf("x1=%.5f;x2=%.5f", x2, x1); // 输出格式为x1=aaaa;x2=bbbb
            } else {
                printf("x1=%.5f;x2=%.5f", x1, x2); // 输出格式为x1=aaaa;x2=bbbb
            }
        }
    } else { // 如果判别式小于0，则方程无实根
        cout << "No answer!"; // 输出No answer!
    }

    return 0;
}
