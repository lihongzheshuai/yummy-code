/**
 * 题目: 【GESP/CSP】编程武器库-3, 十六进制转换十进制
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 2 / 共 5 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-3-hex-dec-conversion/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "请输入一个十六进制数 (如 FF 或 0x1A): ";
    cin >> hex >> num;   // 按十六进制解析输入

    cout << "对应的十进制是: " << dec << num << endl;
    return 0;
}
