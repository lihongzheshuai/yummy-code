/**
 * 题目: 【GESP】C++一级练习BCQM3022，输入-计算-输出-3
 * 题号: 3022
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3022/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int d = 20 - (a + b + c);
    cout << d;
    return 0;
}
