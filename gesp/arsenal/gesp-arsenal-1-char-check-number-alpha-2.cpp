/**
 * 题目: 【GESP/CSP】编程武器库-1, 字符类型判断
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 2 / 共 8 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-1-char-check-number-alpha/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char c = '7';
    if (isdigit(c)) {
        cout << c << " 是数字" << endl;
    } else {
        cout << c << " 不是数字" << endl;
    }
    return 0;
}
