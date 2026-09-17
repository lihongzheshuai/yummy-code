/**
 * 题目: 【GESP】C++一级练习 luogu-B2032, 等差数列末项计算
 * 题号: B2032
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2032/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a, b, n; // 定义变量a, b, n，用于存储输入的三个整数
    cin >> a >> b >> n; // 从标准输入读取三个整数a, b, n
    int d = b - a; // 计算等差数列的公差d
    cout << a + (n - 1) * d; // 输出第n项的值，根据等差数列的公式计算
    return 0; // 返回0，表示程序执行成功
}
