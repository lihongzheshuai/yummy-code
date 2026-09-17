/**
 * 题目: 【GESP/CSP】编程武器库-3, 十六进制转换十进制
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 5 / 共 5 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-3-hex-dec-conversion/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>
using namespace std;

int hexToDec(const string& s) {
    int result = 0;
    for (char c : s) {
        int value;
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else {
            continue; // 跳过不合法字符
        }
        result = result * 16 + value;
    }
    return result;
}

int main() {
    string s = "FE";
    cout << hexToDec(s) << endl;  // 输出 254
    return 0;
}
