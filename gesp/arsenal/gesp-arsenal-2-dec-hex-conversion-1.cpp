/**
 * 题目: 【GESP/CSP】编程武器库-2, 十进制转换十六进制
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 1 / 共 7 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-2-dec-hex-conversion/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n = 255;

    cout << hex << n << endl;              // ff （小写）
    cout << uppercase << hex << n << endl; // FF （大写）
    cout << setw(4) << setfill('0') << hex << n << endl; // 00ff
    return 0;
}
