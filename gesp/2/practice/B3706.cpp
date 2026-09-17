/**
 * 题目: 【GESP】C++二级练习 luogu-B3706 [语言月赛202302] 晚秋绝诗
 * 题号: B3706
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3706/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

using namespace std;
int main() {
    long long x, z; // 定义两个长整型变量 x 和 z
    cin >> x >> z; // 从标准输入读取 x 和 z 的值
    double c; // 定义一个双精度浮点数变量 c
    cin >> c; // 从标准输入读取 c 的值
    long long y = x - 2 * z; // 计算 y 的值
    cout << ceil(y / c); // 输出 y 除以 c 的上整数部分
    return 0; // 返回 0，表示程序正常结束
}
