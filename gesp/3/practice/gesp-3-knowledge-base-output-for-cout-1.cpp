/**
 * 题目: 【GESP】C++三级知识点研究，cout输出进制转换
 * 题号: 
 * 归属: GESP3级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-knowledge-base-output-for-cout/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <iomanip>   // oct, hex, dec, showbase, uppercase
#include <bitset>    // bitset 用于二进制输出

using namespace std;

int main() {
    int value = 255;

    // 十进制（默认）
    cout << "十进制: " << value << endl;

    // 八进制输出
    cout << oct;
    cout << "八进制（无前缀）: " << value << endl;
    cout << showbase << "八进制（带前缀）: " << value << endl;

    // 十六进制输出
    cout << hex;
    cout << "十六进制（小写）: " << value << endl;
    cout << uppercase << "十六进制（大写）: " << value << endl;
    cout << showbase << "十六进制（大写带前缀）: " << value << endl;

    // 恢复十进制
    cout << dec << nouppercase << noshowbase;
    cout << "恢复十进制: " << value << endl;

    // 二进制输出
    cout << "二进制（8位）: " << bitset<8>(value) << endl;
    cout << "二进制（16位）: " << bitset<16>(value) << endl;

    return 0;
}
