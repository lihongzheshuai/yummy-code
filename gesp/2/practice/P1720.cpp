/**
 * 题目: 【GESP】C++二级练习 luogu-P1720 月落乌啼算钱（斐波那契数列）
 * 题号: P1720
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-p1720/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    // 读取输入的n
    int n;
    cin >> n;

    // 计算斐波那契数列通项公式中的第一项：(1+√5)/2的n次方
    double u = pow(((1 + sqrt(5)) / 2), n);

    // 计算斐波那契数列通项公式中的第二项：(1-√5)/2的n次方
    double y = pow(((1 - sqrt(5)) / 2), n);

    // 计算最终结果：两项之差除以√5
    double fn = (u - y) / sqrt(5);

    // 按照题目要求输出保留两位小数的结果
    printf("%.2f", fn);
    return 0;
}
