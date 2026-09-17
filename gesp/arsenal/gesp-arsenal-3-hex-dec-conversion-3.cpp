/**
 * 题目: 【GESP/CSP】编程武器库-3, 十六进制转换十进制
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 3 / 共 5 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-3-hex-dec-conversion/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "FF";      // 十六进制字符串
    string s2 = "0x1A";    // 带 0x 前缀

    int num1 = stoi(s1, nullptr, 16);  // 转换为十进制
    int num2 = stoi(s2, nullptr, 16);

    cout << "num1 = " << num1 << endl;  // 255
    cout << "num2 = " << num2 << endl;  // 26
    return 0;
}
