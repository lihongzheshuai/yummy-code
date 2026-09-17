/**
 * 题目: 【GESP】C++二级练习 luogu-P5726 【深基4.习9】打分
 * 题号: P5726
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-p5726/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    int n; // 定义一个整型变量 n
    cin >> n; // 从标准输入读取 n 的值
    int nmax = 0, nmin = 10; // 定义并初始化两个整型变量 nmax 和 nmin，分别表示最大值和最小值
    int sum = 0; // 定义并初始化一个整型变量 sum 为 0
    for (int i = 0; i < n; i++) { // 循环 n 次
        int x; // 定义一个整型变量 x
        cin >> x; // 从标准输入读取 x 的值
        sum += x; // 将 x 的值加到 sum 中
        nmax = max(x, nmax); // 更新 nmax 为 x 和 nmax 中的较大值
        nmin = min(x, nmin); // 更新 nmin 为 x 和 nmin 中的较小值
    }
    sum = sum - nmax - nmin; // 从 sum 中减去 nmax 和 nmin
    printf("%.2lf", (double)sum / (n - 2)); // 打印结果，保留两位小数
    return 0; // 返回 0，表示程序正常结束
}
