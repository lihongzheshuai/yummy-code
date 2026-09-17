/**
 * 题目: 【GESP】C++三级知识点研究，cout输出进制转换
 * 题号: 
 * 归属: GESP3级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-knowledge-base-output-for-cout/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int x = 255;

    cout << hex << showbase << uppercase;
    cout << "十六进制格式输出: " << x << endl;  // 输出: 0XFF

    // 下一行也会被格式影响（仍是 hex、showbase、uppercase）
    cout << "再次输出十六进制: " << x << endl;  // 输出: 0XFF

    // ✅ 显式恢复为默认设置
    cout << dec << noshowbase << nouppercase;
    cout << "恢复十进制输出: " << x << endl;   // 输出: 255

    // setw 只对下一个输出有效
    cout << setfill('0') << setw(5) << x << " ";
    cout << x << endl;  // 第二个 x 没有被 setw(5) 影响
}
