/**
 * 题目: 【GESP】C++一级练习 luogu-B2044, 有一门课不及格的学生
 * 题号: B2044
 * 归属: GESP1级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b2044/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a, b, c; // 定义三个整数变量a, b, c
    cin >> a >> b >> c; // 从输入流中读取a, b, c的值
    int count = 0; // 初始化计数器count为0
    // 检查a是否小于60，并增加计数器
    if (a < 60) {
        count++;
    }
    // 检查b是否小于60，并增加计数器
    if (b < 60) {
        count++;
    }
    // 检查c是否小于60，并增加计数器
    if (c < 60) {
        count++;
    }
    // 如果计数器的值为1，则输出1，否则输出0
    if (count == 1) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0; // 返回0，表示程序执行成功
}
