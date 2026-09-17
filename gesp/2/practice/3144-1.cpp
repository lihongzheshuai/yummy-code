/**
 * 题目: 【GESP】C++二级练习BCQM3144，26个字母输出
 * 题号: 3144
 * 归属: GESP2级
 * 解法: 解法 1 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-2-bcqm3144/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a = 97;
    for (int i = 1; i <= 26; i++) {
        cout << (char)a << " ";
        a += 1;
    }
    return 0;
}
