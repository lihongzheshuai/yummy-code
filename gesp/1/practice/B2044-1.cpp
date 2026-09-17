/**
 * 题目: 【GESP】C++一级练习 luogu-B2044, 有一门课不及格的学生
 * 题号: B2044
 * 归属: GESP1级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b2044/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a, b, c; // 定义三个整数变量a, b, c
    cin >> a >> b >> c; // 从输入流中读取a, b, c的值
    // 判断条件：如果a和b都大于等于60，并且c小于60，则输出1
    if ((a >= 60 && b >= 60) && c < 60) {
        cout << 1;
    }
    // 判断条件：如果a小于60，并且b大于等于60，并且c大于等于60，则输出1
    else if ((a < 60 && b >= 60) && c >= 60) {
        cout << 1;
    }
    // 判断条件：如果a大于等于60，并且b小于60，并且c大于等于60，则输出1
    else if ((a >= 60 && b < 60) && c >= 60) {
        cout << 1;
    }
    // 如果上述条件都不满足，则输出0
    else {
        cout << 0;
    }
    return 0; // 返回0，表示程序执行成功
}
