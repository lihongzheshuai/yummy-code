/**
 * 题目: 【GESP】C++二级练习 luogu-P5719 【深基4.例3】分类平均
 * 题号: P5719
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-p5719/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    int n; // 定义一个整型变量 n
    cin >> n; // 从标准输入读取 n 的值
    int k; // 定义一个整型变量 k
    cin >> k; // 从标准输入读取 k 的值
    int a = 0, b = 0; // 定义并初始化两个整型变量 a 和 b 为 0
    int ans = 0, bns = 0; // 定义并初始化两个整型变量 ans 和 bns 为 0
    for (int i = 1; i <= n; i++) { // 循环从 1 到 n
        if (i % k == 0) { // 如果 i 能被 k 整除
            a += i; // 将 i 的值加到 a 中
            ans++; // ans 自增 1
        } else { // 如果 i 不能被 k 整除
            b += i; // 将 i 的值加到 b 中
            bns++; // bns 自增 1
        }
    }
    printf("%.1f %.1f", (double)a / (double)ans, (double)b / (double)bns); // 打印结果，保留一位小数
    return 0; // 返回 0，表示程序正常结束
}
