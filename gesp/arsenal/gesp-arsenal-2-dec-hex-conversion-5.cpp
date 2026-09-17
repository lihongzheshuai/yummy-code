/**
 * 题目: 【GESP/CSP】编程武器库-2, 十进制转换十六进制
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 5 / 共 7 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-2-dec-hex-conversion/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>
using namespace std;

// 将0-15的数字转换为对应的十六进制字符
// 参数 val: 0-15之间的整数
// 返回值: 对应的十六进制字符（0-9或A-F）
char toHexChar(int val) {
    return (val < 10) ? '0' + val : 'A' + (val - 10);
}

// 将十进制数转换为十六进制字符串
// 参数 num: 待转换的十进制数
// 返回值: 转换后的十六进制字符串（大写）
string decimalToHex(int num) {
    // 处理0的特殊情况
    if (num == 0) {
        return "0";
    }

    string res;
    // 不断除以16取余，从低位到高位构建十六进制字符串
    while (num > 0) {
        // 取余得到当前位的值（0-15），转换为十六进制字符
        res = toHexChar(num % 16) + res;
        // 除以16，处理下一位
        num /= 16;
    }
    return res;
}

int main() {
    cout << decimalToHex(254) << endl; // FE
}
