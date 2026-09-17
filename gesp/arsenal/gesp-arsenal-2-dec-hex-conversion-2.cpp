/**
 * 题目: 【GESP/CSP】编程武器库-2, 十进制转换十六进制
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 2 / 共 7 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-2-dec-hex-conversion/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 定义一个十进制数 255 用于演示
    int n = 255;

    cout << "0x"  // 输出十六进制前缀
         << uppercase  // 设置大写字母输出模式
         << hex       // 设置十六进制输出模式
         << setw(4)   // 设置输出宽度为4
         << setfill('0')  // 设置填充字符为'0'
         << n        // 输出数字
         << endl;   // 输出 0x00FF
}
