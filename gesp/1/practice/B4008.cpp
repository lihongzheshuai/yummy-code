/**
 * 题目: 【GESP】C++一级练习 luogu-B4008, [语言月赛 202407] true
 * 题号: B4008
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b4008/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 定义变量a和b用于存储输入的两个数
    int a, b;
    // 从标准输入读取两个整数
    cin >> a >> b;
    // 输出三个数:
    // 1. a除以10(第一个人分到的钱)
    // 2. b乘以10(第二个人分到的钱)
    // 3. 10000减去前两个人分到的钱(第三个人分到的钱)
    cout << a / 10 << " " << b * 10 << " " << 10000 - a / 10 - b * 10;
}
