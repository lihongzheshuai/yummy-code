/**
 * 题目: 【GESP】C++二级练习 luogu-B2079, 求出 e 的值
 * 题号: B2079
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b2079/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n; // 输入的整数n，表示计算e时累加到1/n!
    cin >> n; // 读取输入的n
    double ans = 1; // 初始化答案为1，表示e的初始值
    for (int i = 1; i <= n; i++) { // 从1到n累加
        double tmp = 0; // 临时变量，用于存储当前项的值
        long long denominator = 1; // 分母，用于计算i!
        for (int j = 1; j <= i; j++) { // 计算i!
            denominator *= j;
        }
        tmp = 1.0 / denominator; // 计算当前项的值
        ans += tmp; // 累加当前项到答案中
    }
    printf("%.10f", ans); // 输出答案，保留10位小数
    return 0;
}
