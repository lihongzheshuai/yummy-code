/**
 * 题目: 【GESP】C++二级练习 luogu-B2062, 乘方计算
 * 题号: B2062
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b2062/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int a, b; // 定义变量a和b
    cin >> a >> b; // 读取输入的a和b
    cout << pow(a, b); // 输出a的b次方
    return 0;
}
