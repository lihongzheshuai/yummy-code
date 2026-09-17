/**
 * 题目: 【GESP】C++一级真题(202406)luogu-B4000，休息时间
 * 题号: B4000
 * 归属: GESP1级 (202406认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b4000/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 定义变量a, b, c, d来存储输入的时、分、秒和学习时间
    int a, b, c, d;
    // 从标准输入流中读取时、分、秒和学习时间
    cin >> a >> b >> c >> d;
    // 将时、分、秒转换为总秒数
    int n = a * 3600 + b * 60 + c;
    // 计算学习后休息的总秒数
    int i = n + d;
    // 输出休息时刻的时、分、秒
    cout << i / 3600 << " " << i % 3600 / 60 << " " << i % 3600 % 60;
    return 0;
}
