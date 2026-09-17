/**
 * 题目: 【GESP】C++一级练习 luogu-B2052, 简单计算器
 * 题号: B2052
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2052/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a, b; // 定义两个整数变量a和b
    char c; // 定义一个字符变量c，用于存储操作符
    cin >> a >> b >> c; // 从输入流中读取a, b, c的值

    // 检查除数是否为0，并且操作符是否为除号
    if ((b == 0 && c == '/')) {
        cout << "Divided by zero!";
    }
    // 检查操作符是否为加号，并且除数是否不为0
    if (c == '+' && b != 0) {
        cout << a + b; // 执行加法操作
    }
    // 检查操作符是否为减号，并且除数是否不为0
    if (c == '-' && b != 0) {
        cout << a - b; // 执行减法操作
    }
    // 检查操作符是否为乘号，并且除数是否不为0
    if (c == '*' && b != 0) {
        cout << a * b; // 执行乘法操作
    }
    // 检查操作符是否为除号，并且除数是否不为0
    if (c == '/' && b != 0) {
        cout << a / b; // 执行除法操作
    }
    // 检查操作符是否为无效的操作符
    if (((c != '+' && c != '-') && c != '*') && c != '/') {
        cout << "Invalid operator!"; // 输出无效操作符的提示
    }
    return 0; // 返回0，表示程序执行成功
}
