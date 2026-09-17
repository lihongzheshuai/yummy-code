/**
 * 题目: 【GESP/CSP】编程武器库-2, 十进制转换十六进制
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 7 / 共 7 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-2-dec-hex-conversion/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>
using namespace std;

// 将十进制数转换为十六进制字符串（固定4位，带0X前缀）
// 参数：num - 待转换的十进制数
// 返回：转换后的十六进制字符串，格式如"0X00FF"
string decimalToHex(int num) {
    // 定义包含所有十六进制字符的字符数组（0-9和A-F）
    static const char hex_digits[] = "0123456789ABCDEF";
    // 初始化结果字符串，长度为4，用'0'填充
    std::string res(4, '0');

    // 从右向左，每次处理一个十六进制位
    for (int i = 3; i >= 0; --i) {
        // 通过num % 16获取当前位的值(0-15)
        // 然后用这个值作为下标从hex_digits数组中取出对应的字符
        // 例如:如果num % 16 = 15,就会取出hex_digits[15]即'F'
        res[i] = hex_digits[num % 16];
        // num除以16，准备处理下一位
        num /= 16;
    }

    // 添加"0X"前缀并返回结果
    res = "0X" + res;
    return res;
}

int main() {
    cout << decimalToHex(254) << endl; // FE
}
