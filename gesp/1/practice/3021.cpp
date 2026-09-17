/**
 * 题目: 【GESP】C++一级练习BCQM3021，输入-计算-输出-2
 * 题号: 3021
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3021/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    // 定义四个整型变量，用于存储四道题的分数
    int a, b, c, d;
    // 从标准输入读取四个分数
    cin >> a >> b >> c >> d;
    // 计算并输出总分
    cout << a + b + c + d;
    return 0;
}
