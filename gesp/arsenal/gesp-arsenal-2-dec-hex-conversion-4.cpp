/**
 * 题目: 【GESP/CSP】编程武器库-2, 十进制转换十六进制
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 4 / 共 7 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-2-dec-hex-conversion/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

string decimalToHex(int num) {
    ostringstream oss;
    // 设置宽度和填充
    oss << setw(4) << setfill('0');
    // 设置大写和十六进制
    oss << uppercase << hex;
    // 设置显示前缀
    oss << showbase;
    oss << num;
    return oss.str();
}

int main() {
    int n = 255;  // 定义一个十进制数
    string hexStr = decimalToHex(n);  // 调用转换函数，将十进制转为十六进制字符串
    cout << hexStr << endl; // 输出结果：0X00FF（带前缀的大写十六进制）
}
