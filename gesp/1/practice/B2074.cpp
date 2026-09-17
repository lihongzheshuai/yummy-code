/**
 * 题目: 【GESP】C++一级练习 luogu-B2074, 计算星期几
 * 题号: B2074
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2074/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>
using namespace std; // 使用标准命名空间

int main() {
    int n; // 定义一个整数变量n，用于存储输入的整数
    cin >> n; // 从输入流中读取n的值
    int c; // 定义一个整数变量c，用于存储输入的幂次
    cin >> c; // 从输入流中读取c的值
    int mod = n % 7; // 计算n对7的余数，用于确定初始星期几
    int ans = mod; // 初始化答案为mod的值
    for (int i = 1; i < c; i++) { // 循环从1到c-1
        ans %= 7; // 对ans进行取模运算，确保结果在0到6之间
        ans *= mod; // 将ans乘以mod，模拟幂次的计算
    }
    // 根据ans的值输出对应的星期几
    if (ans % 7 == 0) {
        cout << "Sunday";
    }
    if (ans % 7 == 1) {
        cout << "Monday";
    }
    if (ans % 7 == 2) {
        cout << "Tuesday";
    }
    if (ans % 7 == 3) {
        cout << "Wednesday";
    }
    if (ans % 7 == 4) {
        cout << "Thursday";
    }
    if (ans % 7 == 5) {
        cout << "Friday";
    }
    if (ans % 7 == 6) {
        cout << "Saturday";
    }
    return 0; // 返回0，表示程序执行成功
}
