/**
 * 题目: 【GESP/CSP】编程武器库-3, 十六进制转换十进制
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 4 / 共 5 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-3-hex-dec-conversion/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "0xFFend";
    size_t idx;
    int num = stoi(s, &idx, 16);

    cout << "num = " << num << endl;   // 输出 255
    cout << "idx = " << idx << endl;   // 输出 5, 表示第一个未被转换字符的下标位置
    cout << "剩余部分: " << s.substr(idx) << endl;  // 输出 end
    return 0;
}
