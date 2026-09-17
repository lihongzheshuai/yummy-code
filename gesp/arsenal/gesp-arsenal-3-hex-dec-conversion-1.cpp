/**
 * 题目: 【GESP/CSP】编程武器库-3, 十六进制转换十进制
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 1 / 共 5 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-3-hex-dec-conversion/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    int a = 0xFF;   // 十六进制 0xFF 转换后存储为十进制 255
    int b = 0x1A;   // 十六进制 0x1A 转换后存储为十进制 26

    cout << "a = " << a << endl;  // 255
    cout << "b = " << b << endl;  // 26
    cout << "a + b = " << a + b << endl;  // 281
    return 0;
}
