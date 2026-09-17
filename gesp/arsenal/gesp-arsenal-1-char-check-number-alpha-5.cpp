/**
 * 题目: 【GESP/CSP】编程武器库-1, 字符类型判断
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 5 / 共 8 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-1-char-check-number-alpha/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

// 判断字符是否为大写字母的函数
bool isUpperCase(char c) {
    return c >= 'A' && c <= 'Z';
}

int main() {
    char c = 'A';
    if (isUpperCase(c)) {
        cout << c << " 是大写字母" << endl;
    } else {
        cout << c << " 不是大写字母" << endl;
    }
    return 0;
}
