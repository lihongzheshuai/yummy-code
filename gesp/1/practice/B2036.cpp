/**
 * 题目: 【GESP】C++一级练习 luogu-B2036, 输出绝对值
 * 题号: B2036
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2036/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio> // 包含输入输出流头文件
#include <iostream> // 包含输入输出流头文件
using namespace std; // 使用标准命名空间

int main() {
    double a; // 定义浮点数变量a
    cin >> a; // 从标准输入流读取浮点数到a
    if (a >= 0) { // 如果a非负
        printf("%.2f", a); // 直接输出a保留两位小数
    } else { // 如果a为负数
        printf("%.2f", a * -1); // 输出a的绝对值保留两位小数
    }
    return 0; // 主函数返回0，表示程序执行成功
}
