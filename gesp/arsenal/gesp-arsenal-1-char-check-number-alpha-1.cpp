/**
 * 题目: 【GESP/CSP】编程武器库-1, 字符类型判断
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 1 / 共 8 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-1-char-check-number-alpha/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

// 判断字符是否为数字的函数
bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    char c = '7';
    if (isNumber(c)) {
        cout << c << " 是数字" << endl;
    } else {
        cout << c << " 不是数字" << endl;
    }
    return 0;
}
