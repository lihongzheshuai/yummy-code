/**
 * 题目: 【GESP】C++一级练习 luogu-B2071, 余数相同问题
 * 题号: B2071
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2071/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a, b, c; // 定义三个整数a, b, c，用于存储输入的三个正整数
    cin >> a >> b >> c; // 从输入流中读取a, b, c的值
    int i = 2; // 初始化变量i，用于作为除数
    while (true) { // 无限循环，直到找到满足条件的i
        if ((a % i == b % i) && (b % i == c % i)) { // 检查a, b, c除以i的余数是否相同
            cout << i; // 如果相同，输出i
            break; // 跳出循环
        }
        i++; // 如果不相同，i自增1，继续下一轮循环
    }
    return 0; // 返回0，表示程序执行成功
}
